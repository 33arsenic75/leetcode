class Solution {
public:
    string sum(string s){
        int ans = 0;
        for(char c:s)ans+=c-'0';
        return to_string(ans);
    }
    string digitSum(string s, int k) {
        if(s.size()<=k)return s;
        string ans = "";
        string temp;
        for(int i = 0 ; i < s.size() ; i+=k){
            temp = s.substr(i,k);
            ans = ans + sum(temp);
        }
        return digitSum(ans,k);
    }
};