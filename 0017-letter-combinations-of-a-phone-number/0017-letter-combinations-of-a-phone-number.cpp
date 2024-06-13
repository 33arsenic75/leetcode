class Solution {
public:
    vector<vector<string>>mp;
    vector<string>ans;
    void initialize(){
        mp[2] = {"a", "b", "c"};
        mp[3] = {"d", "e", "f"};
        mp[4] = {"g", "h", "i"};
        mp[5] = {"j", "k", "l"};
        mp[6] = {"m", "n", "o"};
        mp[7] = {"p", "q", "r", "s"};
        mp[8] = {"t", "u", "v"};
        mp[9] = {"w", "x", "y", "z"};
    }
    void add(int i){
        vector<string>temp;
        for(string s1:mp[i]){
            for(string s2:ans){
                temp.push_back(s2+s1);
            }
        }
        ans = temp;

    }
    vector<string> letterCombinations(string digits) {
        if(digits==""){
            return vector<string>();
        }
        mp=vector<vector<string>>(10);
        initialize();
        ans=vector<string>{""};
        for(char c:digits){
            add(c-'0');
        }
        return ans;
    }
};