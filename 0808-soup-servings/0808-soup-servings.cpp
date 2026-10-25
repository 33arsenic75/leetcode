using ld = long double;

class Solution {
public:
    unordered_map<long long, ld> dp;

    ld solve(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;

        long long key = 1LL * a * 2000000001LL + b;
        if (dp.count(key)) return dp[key];

        return dp[key] = (
            solve(a - 100, b) +
            solve(a - 75, b - 25) +
            solve(a - 50, b - 50) +
            solve(a - 25, b - 75)
        ) / 4.0;
    }

    double soupServings(int n) {
        if (n >= 5000) return 1.0;
        dp.clear();
        return solve(n, n);
    }
};