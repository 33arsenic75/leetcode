class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<int,int>mp1;
        mp1[0]=1;
        for(int n: nums){
            map<int,int>mp2;
            for(auto&[k,v]:mp1){
                mp2[k+n]+=v;
                mp2[k-n]+=v;
            }
            mp1 = mp2;
        }
        return mp1[target];
    }
};