class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        long long sum = 0;
        long long mi = 100000009;
        long long ma = 0;
        long long mod = 1000000007;
        

        for(long long x: nums) {
            sum += x;
            ma = max(x, ma);
            mi = min(x, mi);
        }

        long long n = nums.size();
        long long ans = LONG_MAX;

        for(long long i = ma; i < 2 * ma; ++i) {
            long long rem = i * n - sum;

            long long  minadd = i - mi;
            long long curr = 0;
            
            if(minadd >= rem - minadd) {
                long long extra = (minadd - (rem - minadd));
                curr += extra * cost1;
                rem -= extra;
            }

            if(rem % 2 == 1) {
                curr += cost1;
                rem--;
            }

            curr += min((long long)cost1 * rem, (long long)cost2 * (rem / 2));
            ans = min(ans, curr);
        }
       
        return ans % mod;
    }
};