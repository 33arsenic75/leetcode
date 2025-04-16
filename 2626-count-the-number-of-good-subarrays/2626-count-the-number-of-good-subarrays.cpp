class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        long long ans = 0;
        long long pairs = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            pairs += freq[nums[right]];
            freq[nums[right]]++;

            while (pairs >= k) {
                ans += (n - right);
                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }
        }

        return ans;
    }
};
