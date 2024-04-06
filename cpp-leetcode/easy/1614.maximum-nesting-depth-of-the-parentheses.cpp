/*
 * @lc app=leetcode id=1614 lang=cpp
 *
 * [1614] Maximum Nesting Depth of the Parentheses
 */

// @lc code=start
class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int temp = 0;
        for(char c:s){
            if(c=='(')temp++;
            else if(c==')')temp--;
            ans = max(ans,temp);
        }
        return ans;
    }
};
// @lc code=end

