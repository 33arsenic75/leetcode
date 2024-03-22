/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        int sum;
        while(i<j){
            sum = numbers[i] + numbers[j];
            if(sum==target){
                return vector<int>{i+1,j+1};
            }
            else if(sum<target)i++;
            else j--;
        }
        return vector<int>();
    }
};
// @lc code=end

