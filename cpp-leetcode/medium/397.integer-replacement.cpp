/*
 * @lc app=leetcode id=397 lang=cpp
 *
 * [397] Integer Replacement
 */

// @lc code=start
#include<unordered_map>
class Solution {
public:

long long integerReplace(long long n, unordered_map<long long, int> &dp){
    if(n<=1)
    return 0;

    if(dp.find(n)!=dp.end())
    return dp[n];
        
    if(n%2==0)
    return dp[n]=1+integerReplace(n/2,dp);
    
    return dp[n]= 1+min(integerReplace(n+1,dp),integerReplace(n-1,dp));
}
    int integerReplacement(int n) {
        unordered_map<long long,int> dp;
        return integerReplace(n, dp);
        
    }
};
// @lc code=end

