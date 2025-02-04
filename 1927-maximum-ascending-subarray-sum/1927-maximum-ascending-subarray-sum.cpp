class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;
        int currentSubarraySum = nums[0];
        for (int currentIdx = 1; currentIdx < nums.size(); ++currentIdx) {
            if (nums[currentIdx] <= nums[currentIdx - 1]) {
                maxSum = max(maxSum, currentSubarraySum);
                currentSubarraySum = 0;
            }
            currentSubarraySum += nums[currentIdx];
        }
        return max(maxSum, currentSubarraySum);
    }
};