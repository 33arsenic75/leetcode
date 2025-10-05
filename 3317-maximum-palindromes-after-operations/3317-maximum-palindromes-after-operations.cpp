class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int cnt[26] = {}, pairs = 0, res = 0;
        vector<int> sizes;
        for (const auto &w : words) {
            for (char ch : w)
                pairs += (++cnt[ch - 'a']) % 2 == 0;
            sizes.push_back(w.size());
        }
        sort(begin(sizes), end(sizes));
        for (int sz : sizes) {
            pairs -= sz / 2;
            res += pairs >= 0;
        }
        return res;
    }
};
