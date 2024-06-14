class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%3!=0)return vector<vector<int>>();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans(n/3);
        for(int i: nums)cout<<i<<' ';
        cout<<endl;
        for(int i=0;i<n;i+=3){
            if(nums[i+2]-nums[i]>k){
                return vector<vector<int>>();
            }
            ans[i/3].push_back(nums[i]);
            ans[i/3].push_back(nums[i+1]);
            ans[i/3].push_back(nums[i+2]);
        }
        return ans;        
    }
};