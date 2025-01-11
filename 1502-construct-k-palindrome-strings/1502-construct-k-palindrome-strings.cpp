class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;
        if (s.length() == k) return true;
        int oddCount = 0;
        for (char chr : s) {
            oddCount ^= 1 << (chr - 'a');
        }
        int setBits = __builtin_popcount(oddCount);
        return __builtin_popcount(oddCount) <= k;
    }
};