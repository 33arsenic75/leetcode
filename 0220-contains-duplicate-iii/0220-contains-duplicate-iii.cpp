class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        int n = nums.size();
        multiset<int> ms;     //to store window elements in sorted order
        
		int i=0, j=0;
        while(j<n)
        {
            auto up = ms.upper_bound(nums[j]);
            if((up != ms.end() and *up-nums[j] <= t) || (up != ms.begin() and nums[j] - *(--up) <= t))
                return true;
            ms.insert(nums[j]);
            
            if(ms.size() == k+1)
            {
                ms.erase(nums[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};