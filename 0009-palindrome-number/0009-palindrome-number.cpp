#include <iostream>
#include <string>
#include <algorithm>  // For std::reverse

class Solution {
public:
    bool isPalindrome(int x) {
        // Convert integer to string
        std::string s = std::to_string(x);

        // Reverse the string
        std::string ss = s;
        std::reverse(ss.begin(), ss.end());

        // Check if the original string is equal to the reversed string
        return (s == ss);
    }
};
