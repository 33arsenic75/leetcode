class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int>cnt(26,0);
        for(char c:s)cnt[c-'a']++;
        int odd = 0;
        for(int i = 0 ; i < 26; i++){
            if(cnt[i]%2 == 1)odd++;
        }
        int n = s.size();
        if(odd <= k && k <= n)return true;
        return false;
    }
};