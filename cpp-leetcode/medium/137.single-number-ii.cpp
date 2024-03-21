/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>cnt(32,0);
        for(int i:nums){
            for(int j=0;j<32;j++){
                if((i&(1<<j))!=0)cnt[j]++;
            }
        }
        int ans = 0;
        for(int i = 0;i<32;i++){
            cout<<cnt[i];
            ans+= (cnt[i]%3)*(1<<i);
        }
        return ans;
    }
};
// @lc code=end

