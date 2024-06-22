class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        function<bool(long long)>check = [&](long long k){
            long long time = 0;
            for(int i:piles){
                time += (i+k-1)/k;
            }
            return (time<=h);
        };
        long long low = 1, high = 1e14, ans = 0, mid = 0;
        while(low <= high){
            mid = low + (high - low)/2;
            if(check(mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};