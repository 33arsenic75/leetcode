using ll = long long;
const ll MOD = 1e9 + 7;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> cnt(32, 0);

        for (int n : nums) {
            #pragma unroll
            for (int i = 0; i < 32; i++) {
                cnt[i] += (n >> i) & 1;
            }
        }

        ll ans = 0;

        while (k--) {
            ll num = 0;
            #pragma unroll
            for (int i = 31; i >= 0; i--) {
                if (cnt[i] > 0) {
                    cnt[i]--;
                    num |= (1LL << i);
                }
            }

            ans = (ans + num * num % MOD) % MOD;
        }

        return ans;
    }
};