class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long n = nums.size();
        vector<long long>mx(n);
        mx[n-1] = nums[n-1];
        for(long long i = n-2 ; i >= 0 ; i--){
            long long nn = nums[i];
            mx[i] = max(mx[i+1], nn);
        }
        vector<long long>diff(n);
        long long minn = 1000000;
        long long maxx = nums[0];
        for(long long i = 1 ; i < n ; i++){
            // diff[i] = nums[i] - minn;
            // minn = min(minn, nums[i]);
            long long nn = nums[i];
            diff[i] = maxx - nn;
            maxx = max(maxx, nn);
        }
        long long ans = 0;
        for(long long i = 0 ; i < n - 1 ; i++){
            ans = max(ans, diff[i]*mx[i+1]);
        }
        return ans;
    }
};