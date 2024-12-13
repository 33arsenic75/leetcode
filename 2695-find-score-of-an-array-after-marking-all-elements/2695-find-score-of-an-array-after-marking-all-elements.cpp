class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;  // Min-heap based on value

        // Build the min-heap with (value, index) pairs
        for (int i = 0; i < n; i++) {
            minHeap.push({nums[i], i});
        }

        long long score = 0;  // Use long long to handle overflow

        // Process elements in min-heap
        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            int num = curr.first;
            int idx = curr.second;

            if (nums[idx] != -1) {  // Process only if not already marked
                score += num;
                nums[idx] = -1;  // Mark the current index
                if (idx > 0 && nums[idx - 1] != -1) {
                    nums[idx - 1] = -1;  // Mark the left neighbor
                }
                if (idx < n - 1 && nums[idx + 1] != -1) {
                    nums[idx + 1] = -1;  // Mark the right neighbor
                }
            }
        }

        return score;
    }
};