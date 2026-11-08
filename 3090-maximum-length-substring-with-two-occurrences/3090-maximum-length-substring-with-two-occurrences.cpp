class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int> cnt(26, 0);

        int l = 0, ans = 0;

        for (int r = 0; r < n; r++) {
            int c = s[r] - 'a';
            cnt[c]++;

            while (cnt[c] > 2) {
                cnt[s[l] - 'a']--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};