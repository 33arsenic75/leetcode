class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        function<bool(int)>f = [&](int target){
            int total = 0;
            for(int n:nums){
                total += (n-1)/target;
            }
            return total<=maxOperations;
        };
        int low = 1, high = 0, ans = 0, mid = 0;
        for(int n:nums){
            high = max(high,n);
        }
        while(low<=high){
            mid = low + (high-low)/2;
            cout<<low<<" "<<mid<<" "<<high<<'\n';
            if(f(mid)){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }   
};