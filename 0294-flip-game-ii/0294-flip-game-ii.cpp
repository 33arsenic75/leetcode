class Solution {
public:
    bool canWin(string currentState) {
        int n = currentState.size();
        vector<int> grundy(n + 1, 0);
        vector<int> seen(2 * n + 3, -1);

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < len - 1; i++) {
                int x = grundy[i] ^ grundy[len - i - 2];
                seen[x] = len;
            }

            int g = 0;
            while (seen[g] == len) g++;
            grundy[len] = g;
        }

        int nimSum = 0, run = 0;

        for (char c : currentState) {
            if (c == '+') {
                run++;
            } else {
                nimSum ^= grundy[run];
                run = 0;
            }
        }

        nimSum ^= grundy[run];
        return nimSum != 0;
    }
};