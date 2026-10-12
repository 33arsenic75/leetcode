
class Solution {
public:
    vector<vector<vector<vector<int>>>> dp;

    bool isScramble(string& s1, string& s2,
                    int i1, int j1, int i2, int j2) {

        if (j1 - i1 != j2 - i2) return false;

        if (i1 == j1)
            return s1[i1] == s2[i2];

        int &ans = dp[i1][j1][i2][j2];

        if (ans != -1) return ans;

        ans = 0;
        int length = j1 - i1 + 1;

        for (int l = 1; l < length; l++) {
            // No swap
            if (isScramble(s1, s2, i1, i1 + l - 1,
                           i2, i2 + l - 1) &&
                isScramble(s1, s2, i1 + l, j1,
                           i2 + l, j2)) {
                return ans = 1;
            }

            // Swap
            if (isScramble(s1, s2, i1, i1 + l - 1,
                           j2 - l + 1, j2) &&
                isScramble(s1, s2, i1 + l, j1,
                           i2, j2 - l)) {
                return ans = 1;
            }
        }

        return ans;
    }

    bool isScramble(string s1, string s2) {
        int n = s1.size();

        if (s1.size() != s2.size()) return false;

        dp.assign(n, vector<vector<vector<int>>>(
            n, vector<vector<int>>(
                n, vector<int>(n, -1)
            )
        ));

        return isScramble(s1, s2, 0, n - 1, 0, n - 1);
    }
};
