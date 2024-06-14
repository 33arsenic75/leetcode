class Solution {
public:
    // bool isSubsequence(string s, string t) {
    //     if(s.empty())return true;
    //     else if(t.empty())return false;
    //     else if(s[0]==t[0])return isSubsequence(s.substr(1),t.substr(1));
    //     return isSubsequence(s,t.substr(1));
    // }
    bool isSubsequence(string s,string t){
        if(s.empty())return true;
        else if(t.empty())return false; 
        int i=0;int j=0;
        while(j<t.size() && i<s.size()){
            if(s[i]==t[j]){i++;j++;}
            else j++;
        }
        return (i==s.size());
    }
};