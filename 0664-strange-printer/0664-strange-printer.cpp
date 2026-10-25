class Solution {
public:
    int strangePrinter(string t) {
        int n = t.size();
        if (n == 0) return 0;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        function<int(int, int)> f = [&](int i, int j) -> int {
            if (i > j) return 0;
            if (i == j) return 1;
            int &res = dp[i][j];
            if (res != -1) return res;

            res = 1 + f(i + 1, j);                    // s[i]'s stroke covers only i
            for (int k = i + 1; k <= j; k++)
                if (t[k] == t[i])                     // extend s[i]'s stroke to k
                    res = min(res, f(i + 1, k - 1) + f(k, j));
            return res;
        };

        return f(0, n - 1);
    }
};