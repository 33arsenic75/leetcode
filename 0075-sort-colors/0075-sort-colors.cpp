class Solution {
public:
    void sortColors(vector<int>& nums) {
         int s=0,e=nums.size()-1,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0 &&i!=s)
            {
                swap(nums[i],nums[s]);
                i--;
                s++;
            }
            if(nums[i]==2&&i<e)
            {
                swap(nums[i],nums[e]);
                e--;
                i--;
            }
        }
    }
};