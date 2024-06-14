class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 0;
        int min1 = *min_element(nums.begin(),nums.end());
        int max1 = *max_element(nums.begin(),nums.end());
        int gap = max(1, (max1 - min1) / (int(nums.size()) - 1));
        int bucketcnt = (max1 - min1) / gap + 1; // Calculate the number of buckets
        vector<int>maxx(bucketcnt,-1);
        vector<int>minn(bucketcnt,max1 + 1);
        for(int num:nums){
            int idx = (num-min1)/gap;
            minn[idx] = min( minn[idx], num);
            maxx[idx] = max( maxx[idx], num);
        }
        int ans = 0, prev_min = min1;
        for(int i = 0; i < bucketcnt; i++){
            if(minn[i] == max1 + 1)continue;
            ans = max ( ans , minn[i]-prev_min ) ;
            prev_min = maxx[i];
        }
        return ans;
    }
};