/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    int n,m;
    bool f;
    void help(string s, string p, int i, int j){
        if(i==n && j == m){f=true;return;}
        while(p[j]!='.' && p[j]!='*' && i<n && j<m){
            if(p[i]==s[j]){i++;j++;}
            else return;
        }
        while(p[j]=='.' && i<n && j<m){i++;j++;}
        if(p[j]=='*'){
            j++;
            while(i<=n){
                help(s,p,i,j);
                i++;
            }
        }

    }
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        f = false;
        help(s,p,0,0);le
        return f;
    }
};
// @lc code=end

