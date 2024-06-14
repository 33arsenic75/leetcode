class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            sum-=(int)s[i];
        }
        for(int i=0;i<t.size();i++){
            sum+=(int)t[i];
        }
        return static_cast<char>(sum);
    }
};