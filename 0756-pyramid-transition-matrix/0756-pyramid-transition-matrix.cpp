class Solution {
public:
    vector<int> nxt[26][26];   // nxt[a][b] = possible chars above
    unordered_map<string, bool> memo;
    bool built = false;

    void build(vector<string>& allowed) {
        for (auto &s : allowed) {
            nxt[s[0]-'A'][s[1]-'A'].push_back(s[2]-'A');
        }
        built = true;
    }

    bool dfs(const string &bottom) {
        if (bottom.size() == 1) return true;
        if (memo.count(bottom)) return memo[bottom];

        int n = bottom.size();
        string next(n - 1, 'A');

        function<bool(int)> gen = [&](int i) {
            if (i == n - 1)
                return dfs(next);

            int a = bottom[i] - 'A';
            int b = bottom[i + 1] - 'A';

            for (int c : nxt[a][b]) {
                next[i] = char('A' + c);
                if (gen(i + 1)) return true;
            }
            return false;
        };

        return memo[bottom] = gen(0);
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        if (!built) build(allowed);
        return dfs(bottom);
    }
};
