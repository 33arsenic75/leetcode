class Solution {
public:
    vector<int> dp;

    int nim(int n) {
        if (n == 0) return 1;
        if (n == 1) return 0;

        if (dp[n] != -1) return dp[n];

        return dp[n] = (1 + nim(n - 1)) ^ (1 + nim(n - 2));
    }

    bool findGameWinner(int n) {
        dp.assign(n + 1, -1);
        return nim(n);
    }
};