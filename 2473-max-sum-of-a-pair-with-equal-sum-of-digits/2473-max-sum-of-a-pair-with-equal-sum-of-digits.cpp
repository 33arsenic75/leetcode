class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int result = -1;
        int digitMapping[82] = {};
        for (int element : nums) {
            int digitSum = 0;
            for (int currValue = element; currValue; currValue /= 10) {
                int currDigit = currValue % 10;
                digitSum += currDigit;
            }
            if (digitMapping[digitSum] > 0) {
                result = max(result, digitMapping[digitSum] + element);
            }
            digitMapping[digitSum] = max(digitMapping[digitSum], element);
        }
        return result;
    }
};