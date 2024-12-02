class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(string str:strs){
            string s2 = str;
            sort(s2.begin(),s2.end());
            mp[s2].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto&p:mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};