class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int minReward = 1, maxReward = *max_element(nums.begin(), nums.end()),
            totalHouses = nums.size();
        while (minReward < maxReward) {
            int midReward = (minReward + maxReward) / 2;
            int possibleThefts = 0;
            for (int index = 0; index < totalHouses; ++index) {
                if (nums[index] <= midReward) {
                    possibleThefts += 1;
                    index++;
                }
            }
            if (possibleThefts >= k)
                maxReward = midReward;
            else
                minReward = midReward + 1;
        }
        return minReward;
    }
};