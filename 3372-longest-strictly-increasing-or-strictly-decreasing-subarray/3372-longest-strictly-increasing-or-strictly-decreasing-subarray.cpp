class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incLength = 1, decLength = 1;
        int maxLength = 1;
        for (int pos = 0; pos < nums.size() - 1; pos++) {
            if (nums[pos + 1] > nums[pos]) {
                incLength++;
                decLength = 1;
            } else if (nums[pos + 1] < nums[pos]) {
                decLength++;
                incLength = 1;
            } else {
                incLength = 1;
                decLength = 1;
            }
            maxLength = max(maxLength, max(incLength, decLength));
        }
        return maxLength;
    }
};