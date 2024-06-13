class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        int n = nums.size();

        vector<int> ans;

        for(int i=0;i<n;i++) {
            int curr = nums[i];

            int rem = target-curr;

            if(mp.find(rem) != mp.end()) {
                ans.push_back(mp[rem]);
                ans.push_back(i);
                return ans;
            }

            mp[curr] = i;
        }

        return ans;
    }
};