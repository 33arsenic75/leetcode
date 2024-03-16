/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int s1 = haystack.size(), s2 = needle.size();
        if (s2 == 0) return 0;
        int i = 0, j = 0;
        while (i < s1) {
            while (i < s1 && j < s2 && haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j == s2) return i - s2; 
            i = i - j + 1;
            j = 0;
        }
        return -1;
    }
};

// @lc code=end

