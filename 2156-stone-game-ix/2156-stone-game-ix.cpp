class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int f[3] = {0, 0, 0};

        for (auto& s : stones)
            f[s % 3]++;

        return f[0] & 1 ? abs(f[1] - f[2]) > 2 : min(f[1], f[2]) > 0;
    }
};