class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<k)
        {
            return -1.0;
        }
        int sum=0;
        for(int i=0;i<k;i++)
        {
            sum+= nums[i];
        }
        int maxi=sum;
        for(int i=1;i<=n-k;i++)
        {
            sum=sum-nums[i-1];
            sum+=nums[i+k-1];
            maxi=max(maxi,sum);
            // cout<<maxi<<endl;
        }
        double ans=(double)maxi/(double)k;
        return ans;
    }
};