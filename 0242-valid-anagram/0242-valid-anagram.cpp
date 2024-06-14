class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>m;
        for(char x:s)m[x]++;
        for(char x:t)m[x]--;
        for(pair<char,int>x:m){if(x.second!=0)return false;}
        return true;
    }
};