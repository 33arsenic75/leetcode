class Solution {
public:
    string repeatLimitedString(string s, int lim) {
        int freq[26] = {0};
        for(auto &i: s)freq[i-'a']++;
        string ans = "";
        int r = 25, l = 24;
        while(r >= l){
            if(r == l && l)l--;
            
            while(freq[r]){
                while(l && freq[l] == 0)l--;
                if(!ans.empty() && ans.back() == (char)('a'+r)){
                    if(freq[l] > 0 && ans.back() !=  (char)('a'+l)){
                        ans += (char)('a'+l);
                        freq[l]--;
                    }
                }
                if(ans.empty() || ans.back() != (char)('a'+r)){
                    ans.append(min(freq[r], lim), (char)('a'+r));
                    freq[r] -= min(freq[r], lim);
                }else break;
            }

            while(l && freq[l] == 0)l--;
            if(freq[l] == 0)break;
            r--;
        }
        return ans;
    }
};