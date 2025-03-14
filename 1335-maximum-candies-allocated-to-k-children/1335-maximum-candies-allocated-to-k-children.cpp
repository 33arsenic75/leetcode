class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long ans = 0;
        long long n = candies.size();
        long long low = 1, high = accumulate(candies.begin(),candies.end(),0ll);
        long long mid = 0;

        while(low <= high){
            mid = low + (high-low)/2;
            long long possible = 0;
            for(int i = 0 ; i < n ; i++){
                possible += candies[i]/mid;
            }
            if(possible >= k){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};