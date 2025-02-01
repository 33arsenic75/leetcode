class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int index = 0; index < nums.size() - 1; index++) {
            if ((nums[index] & 1) ^ (nums[index + 1] & 1) == 0) {
                return false;
            }
        }
        return true;
    }
};