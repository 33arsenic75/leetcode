class Solution {
public:
    int idxpos(vector<int>&nums){
        int l = 0, h = nums.size()-1, m;
        int ans = nums.size();
        while(l<=h){
            m = l + (h-l)/2;
            if(nums[m]>0){
                ans = m;
                h = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return nums.size()-ans;
    }

    int idxneg(vector<int>&nums){
        int l = 0, h = nums.size() - 1, m;
        int ans = -1;
        while(l<=h){
            m = l + (h-l)/2;
            if(nums[m]<0){
                ans = m;
                l = m + 1;
            }
            else{
                h = m - 1;
            }
        }
        return ans + 1;
    }
    int maximumCount(vector<int>& nums) {
        return max(idxpos(nums),idxneg(nums));
    }
};