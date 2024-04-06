/*
 * @lc app=leetcode id=292 lang=cpp
 *
 * [292] Nim Game
 */

// @lc code=start
#include<vector>
class Solution {
public:
    bool canWinNim(int n) {
        vector<int>a(max(n+1,4),false);
        a[1]=true;
        a[2]=true;
        a[3]=true;
        for(int i = 4; i < a.size(); i++){
            a[i] = !(a[i-1] && a[i-2] && a[i-3]); 
        }
        return a[n];
    }
};
// @lc code=end

