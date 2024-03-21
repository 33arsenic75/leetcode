/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s=="")return true;
        string ss;
        for(string r:wordDict){
            if(s.substr(0,r.size()) == r){
                ss = s.substr(r.size());
                if(wordBreak(ss,wordDict))return true;
            }
        }
        return false;
    }
};
// @lc code=end

