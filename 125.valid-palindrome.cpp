/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    char tolower(char c){
        if('a'<=c && c<='z')return c;
        else if('A'<=c && c<='Z')return c + 32;
        else if('0'<=c && c<='9')return c;
        else return ' ';
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        char c1, c2;
        while(j>i){
            c1 = tolower(s[i]);
            c2 = tolower(s[j]);
            if(c1==' ')i++;
            else if(c2==' ')j--;
            else if(c1==c2){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

