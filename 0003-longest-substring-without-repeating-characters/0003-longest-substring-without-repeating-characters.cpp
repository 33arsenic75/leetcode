/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>occurence(128,0);
        int current = 0, ans = 0;
        int i = 0, j = 0;
        int n = s.size();
        while(i<n && j<n){
            while(occurence[s[j]]==0 && j<n){
                occurence[s[j]]++;
                j++;
            }
            current = j-i;
            ans = max(ans,current);
            while(s[i]!=s[j] && i<j){
                occurence[s[i]]--;
                i++;
            }
            i++;j++;
        }
        ans = max(ans,j-i);
        return ans;
    }
};
// @lc code=end

