class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min-heap: (value, listIndex, elementIndex)
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        int k = nums.size();
        int currentMax = INT_MIN;

        // Initialize with the first element of each list
        for (int i = 0; i < k; i++) {
            pq.emplace(nums[i][0], i, 0);
            currentMax = max(currentMax, nums[i][0]);
        }

        vector<int> bestRange = {0, INT_MAX};

        while (true) {
            auto [val, listIdx, elemIdx] = pq.top();
            pq.pop();

            // Update answer if better range found
            if (currentMax - val < bestRange[1] - bestRange[0]) {
                bestRange = {val, currentMax};
            }

            // Move to next element in that list
            if (elemIdx + 1 == nums[listIdx].size()) {
                break; // can't extend further
            }
            int nextVal = nums[listIdx][elemIdx + 1];
            pq.emplace(nextVal, listIdx, elemIdx + 1);
            currentMax = max(currentMax, nextVal);
        }

        return bestRange;
    }
};
