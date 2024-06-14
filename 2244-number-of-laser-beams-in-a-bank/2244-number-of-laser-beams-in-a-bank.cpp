class Solution {
public:
    int count(string s) {
        int ans = 0;
        for (char c : s) ans += (c == '1');
        return ans;
    }

    vector<int> help(vector<string>& bank) {
        vector<int> ans;
        int temp;
        for (int i = 0; i < bank.size(); i++) {
            temp = count(bank[i]);
            if (temp) ans.push_back(temp);
        }
        return ans;
    }

    int numberOfBeams(vector<string>& bank) {
        vector<int> ans = help(bank);
        if (ans.empty()) return 0;
        
        int result = 0;
        for (int i = 0; i < ans.size() - 1; i++) {
            result += ans[i] * ans[i + 1];
        }
        return result;
    }
};
