#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        const long long INF = (long long)4e18;
        int L = numLaps;
        vector<long long> best(L+1, INF);

        for (auto &t : tires) {
            long long f = t[0];
            long long r = t[1];

            long long cur = f;
            long long sum = 0;
            for (int k = 1; k <= L; ++k) {
                sum += cur;
                if (sum < best[k]) best[k] = sum;

                if (k == L) break;
                if (cur > LLONG_MAX / max(1LL, r)) break;
                long long nextLap = cur * r;
                if (nextLap > f + changeTime) break;
                cur = nextLap;
            }
        }

        int maxConsec = 0;
        for (int k = 1; k <= L; ++k) if (best[k] < INF) maxConsec = k;
        vector<long long> dp(L+1, INF);
        dp[0] = 0;

        for (int i = 1; i <= L; ++i) {
            for (int j = 1; j <= min(i, maxConsec); ++j) {
                if (best[j] == INF) continue;
                if (j == i) {
                    dp[i] = min(dp[i], best[j]);
                } else {
                    dp[i] = min(dp[i], dp[i - j] + changeTime + best[j]);
                }
            }
        }

        return (int)dp[L];
    }
};
