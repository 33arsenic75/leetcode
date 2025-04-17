class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = 0;
        for (auto& [num, indices] : mp) {
            int sz = indices.size();
            for (int i = 0; i < sz; i++) {
                for (int j = i + 1; j < sz; j++) {
                    if ((indices[i] * indices[j]) % k == 0)
                        ans++;
                }
            }
        }

        return ans;
    }
};
