class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>bits(n+1,vector<int>(32,0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < 32 ; j++){
                bits[i+1][j] = bits[i][j]+((nums[i]>>j)&1);
            }
        }
        function<bool(int,int)>check = [&](int start, int end){
            for(int j = 0 ; j < 32 ; j++){
                if(bits[end][j]-bits[start-1][j]>1)return false;
            }
            return true;
        };
        int result = 1;
        for(int i = 1 ; i <= n ; i++){
            int high = n, low = i+1, mid = 0, ans = 0;
            while(low<=high){
                mid = low + (high-low)/2;
                if(check(i,mid)){
                    ans = mid;
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            result = max(result,ans-i+1);
        }
        return result;
    }
};