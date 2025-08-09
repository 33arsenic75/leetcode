class Solution {
public:

int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
    const int INF = 1e9;
    vector<int> best(numLaps+1, INF);

    // Step 1: Precompute best continuous time per lap count
    for (auto &tire : tires) {
        long long f = tire[0], r = tire[1];
        long long lapTime = f, total = f;
        best[1] = min(best[1], (int)f);
        for (int l = 2; l <= numLaps; l++) {
            lapTime *= r;
            if (lapTime > f + changeTime) break; // Not worth continuing
            total += lapTime;
            best[l] = min(best[l], (int)total);
        }
    }

    // Step 2: Race DP
    vector<int> dp(numLaps+1, INF);
    dp[0] = 0;
    for (int l = 1; l <= numLaps; l++) {
        for (int k = 1; k <= l; k++) {
            if (k == l) dp[l] = min(dp[l], best[k]);
            else dp[l] = min(dp[l], dp[l-k] + changeTime + best[k]);
        }
    }
    return dp[numLaps];
}

};