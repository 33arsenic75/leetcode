class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long n = nums1.size();
        if(k==0){
            for(int i = 0 ; i < n ; i++){
                if(nums1[i]!=nums2[i])return -1;
            }
            return 0;
        }
        long long total = 0;
        long long t1 = accumulate(nums1.begin(),nums1.end(),0ll);
        long long t2 = accumulate(nums2.begin(),nums2.end(),0ll);
        if(t1!=t2)return -1;
        for(long long i = 0 ; i < n ; i++){
            long long diff = nums2[i]-nums1[i];
            if(diff%k!=0)return -1;
            total += abs(diff);
        }
        if(total%(2*k)!=0)return -1;
        return total/(2*k);
    }
};