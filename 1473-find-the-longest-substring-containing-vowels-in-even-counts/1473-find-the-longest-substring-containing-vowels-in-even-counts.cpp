#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findTheLongestSubstring(std::string s) {
        std::unordered_map<int, int> mp;
        mp[0] = -1;
        int res = 0, curr = 0;
        std::string vowels = "aeiou";
        for (int i = 0; i < s.size(); ++i) {
            // Check if the current character is a vowel
            size_t pos = vowels.find(s[i]);
            if (pos != std::string::npos) {
                curr ^= (1 << pos);
            }
            // If the current state has been seen before, update the result
            if (mp.find(curr) != mp.end()) {
                res = std::max(res, i - mp[curr]);
            } else {
                mp[curr] = i;
            }
        }
        return res;
    }
};
