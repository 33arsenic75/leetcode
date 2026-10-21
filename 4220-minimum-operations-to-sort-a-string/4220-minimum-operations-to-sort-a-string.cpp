class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end())) return 0;
        if (n == 2) return -1;

        string target = s;
        sort(target.begin(), target.end());

        if (s[0] == target[0] || s[n - 1] == target[n - 1])
            return 1;

        string t = s;
        sort(t.begin() + 1, t.end());
        sort(t.begin(), t.end() - 1);
        if (t == target) return 2;

        t = s;
        sort(t.begin(), t.end() - 1);
        sort(t.begin() + 1, t.end());
        if (t == target) return 2;

        return 3;
    }
};