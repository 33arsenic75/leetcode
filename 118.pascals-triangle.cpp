/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            vector<int>temp(i,1);
            for(int j = 1; j<i-1; j++){
                temp[j] = ans[i-1][j] + ans[i-1][j-1];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

