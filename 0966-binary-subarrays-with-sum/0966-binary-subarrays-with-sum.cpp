class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       unordered_map<int,int> mpp;
        mpp[0]=1;
        int count=0,n=nums.size(),remove=0;
        long long sum=0;
        for(int i=0;i<n;i++) {
            sum+= nums[i];
            remove=sum-goal;
            if(mpp.find(remove) != mpp.end())
                count+= mpp[remove];
            mpp[sum]++;
        }
        return count;  
    }
};