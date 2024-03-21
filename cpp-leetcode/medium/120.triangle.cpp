/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    int sz;
    vector<vector<int>>trg;
    void process(int idx){
        if(idx<0)return;
        for(int i = 0;i<idx+1;i++){
            trg[idx][i] = trg[idx][i] + min(trg[idx+1][i],trg[idx+1][i+1]);
        }
        process(idx-1);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        sz = triangle.size();
        trg = triangle;
        process(sz-2);
        return trg[0][0];
    }
};
// @lc code=end

