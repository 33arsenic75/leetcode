/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

// @lc code=start
class Solution {
public:
    string makeGood(string s) {
        stack<char>stk;
        int temp;
        for(char c:s){
            if(stk.empty())stk.push(c);
            else{
                if(abs(c-stk.top())==32)stk.pop();
                else stk.push(c);
            }
        }
        string ans(stk.size());
        for(int i = stk.size()-1; i>=0;i--){
            ans[i]=stk.top();
            stk.pop();
        }
        return ans;
    }
};
// @lc code=end

