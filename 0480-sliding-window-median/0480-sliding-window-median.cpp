class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<int> left, right;  // left = max half, right = min half

        auto balance = [&]() {
            // Ensure |left| == |right| OR |left| == |right| + 1
            while (left.size() > right.size() + 1) {
                right.insert(*prev(left.end()));
                left.erase(prev(left.end()));
            }
            while (right.size() > left.size()) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
            if (!left.empty() && !right.empty() && *prev(left.end()) > *right.begin()) {
                int l = *prev(left.end());
                int r = *right.begin();
                left.erase(prev(left.end()));
                right.erase(right.begin());
                left.insert(r);
                right.insert(l);
            }
        };

        auto getMedian = [&]() -> double {
            if (k % 2) {
                return *prev(left.end());
            } else {
                return ((double)*prev(left.end()) + *right.begin()) / 2.0;
            }
        };

        // initialize first window
        for (int i = 0; i < k; i++) {
            left.insert(nums[i]);
            balance();
        }
        ans.push_back(getMedian());

        for (int i = k; i < nums.size(); i++) {
            int out = nums[i - k];
            int in = nums[i];

            // erase outgoing element
            if (left.find(out) != left.end()) {
                left.erase(left.find(out));
            } else {
                right.erase(right.find(out));
            }

            // insert new element
            if (!left.empty() && in <= *prev(left.end())) {
                left.insert(in);
            } else {
                right.insert(in);
            }

            balance();
            ans.push_back(getMedian());
        }

        return ans;
    }
};
