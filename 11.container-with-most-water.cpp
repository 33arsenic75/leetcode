/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1;
        int ans = min(height[i],height[j])*(n-1);
        int current = 0;
        while ( i < j ){
            if(height[i] > height[j] )j--;
            else i++;
            current = min(height[i],height[j])*(j-i);
            ans = max(ans,current);
        }
        return ans;
        
    }
};
// @lc code=end

