/*
 * @lc app=leetcode id=390 lang=cpp
 *
 * [390] Elimination Game
 */

// @lc code=start
class Solution {
public:
    int lastRemaining(int n) {
        if(n==1)return 1;
        int ord = 1;
        int ans = 1;
        int remain = n;
        bool left = 0;
        while(remain>1){
            if(left==0 || remain%2 ==1 ){
                    ans = ans + ord;
            }
            ord = ord*2;
            remain= remain/2;
            left = !left;
        }
        return ans;
    }
};
// @lc code=end

