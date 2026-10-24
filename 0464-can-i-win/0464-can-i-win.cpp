class Solution {
public:
    vector<int> memo;

    bool canWin(int bitmask, int desiredTotal, int max_bit) {
        if (desiredTotal <= 0) return false;

        if (memo[bitmask] != -1)
            return memo[bitmask];

        for (int i = 1; i <= max_bit; i++) {
            if (!((bitmask >> i) & 1)) {
                if (i >= desiredTotal)
                    return memo[bitmask] = true;

                if (!canWin(bitmask | (1 << i), desiredTotal - i, max_bit))
                    return memo[bitmask] = true;
            }
        }

        return memo[bitmask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;

        int total = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (total < desiredTotal) return false;

        memo.assign(1 << (maxChoosableInteger + 1), -1);

        return canWin(0, desiredTotal, maxChoosableInteger);
    }
};