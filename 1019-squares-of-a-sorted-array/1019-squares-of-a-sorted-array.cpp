class Solution {
public:
    static bool comp(int&a,int&b){
        return abs(a)<abs(b);
    }
    vector<int> sortedSquares(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        int n=nums.size();
        for(int i=0;i<n;i++)nums[i]*=nums[i];
        return nums;
    }
};