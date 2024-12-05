class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();
        int st = 0;
        int en = n - 1;
        int ans;
        while(st<=en){
            int mid = st + (en-st)/2;
            if(mid-1<0 || mid+1>=n || nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                ans = nums[mid];
                break;
            }
            else if(nums[mid] == nums[mid-1] && (mid-st+1) % 2==0){
                st = mid+1;
            }
            else if(nums[mid] == nums[mid-1] && (mid-st+1) % 2!=0){
                en = mid-2;
            }
            else if(nums[mid] == nums[mid+1] && (n-mid)%2 == 0){
                en = mid-1;
            }
            else if(nums[mid] == nums[mid+1] && (n-mid)%2 != 0){
                st = mid+2;
            }
            
        }
        return ans;
    }
};