class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int>one;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i]==1)one.push_back(i);
        }
        // for(int i:one )cout<<i<<" ";
        // cout<<"\n";
        for(int i = 1 ; i < one.size() ; i++){
            if(one[i]-one[i-1]-1 < k)return false;
        }
        return true;
    }
};