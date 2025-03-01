class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int writeIndex = 0;
        for (int index = 0; index < n; index++) {
            if (index < n - 1 && nums[index] == nums[index + 1] &&
                nums[index] != 0) {
                nums[index] *= 2;
                nums[index + 1] = 0;
            }
            if (nums[index] != 0) {
                if (index != writeIndex) {
                    swap(nums[index], nums[writeIndex]);
                }
                writeIndex++;
            }
        }
        return nums;
    }
};