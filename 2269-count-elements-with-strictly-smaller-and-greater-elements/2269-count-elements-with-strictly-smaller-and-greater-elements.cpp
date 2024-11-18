class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        int mn = *min_element(nums.begin(),nums.end());
        int cnt = n;
        cout<<mx<<" "<<mn;
        for(int i = 0 ; i < n ; i++){
            if(nums[i]==mn)cnt--;
            else if(nums[i]==mx)cnt--;
        }
        return cnt;
    }
};