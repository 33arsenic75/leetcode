class Solution {
public:
    bool isMatch(string s, string p) {
        // Initialize a 2D vector memory with dimensions (s.size() + 1) x (p.size() + 1)
        vector<vector<bool>> memory(s.size() + 1, vector<bool>(p.size() + 1, false));
        // Set memory[s.size()][p.size()] to true since an empty substring of s and an empty pattern p match
        memory[s.size()][p.size()] = true;

        // Iterate through the substrings of s and patterns p from the end towards the beginning
        for (int i = s.size(); i >= 0; i--) {
            for (int j = p.size() - 1; j >= 0; j--) {
                // Check if the current characters match or if the pattern character is '.'
                bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');

                if (j + 1 < p.size() && p[j + 1] == '*') {
                    // If the next character in the pattern is '*', handle the '*' wildcard character
                    memory[i][j] = memory[i][j + 2];
                    if (match) {
                        memory[i][j] = memory[i + 1][j] || memory[i][j];
                    }
                } else if (match) {
                    // If the characters match, move to the next characters in both strings
                    memory[i][j] = memory[i + 1][j + 1];
                }
            }
        }

        // Return memory[0][0], which represents whether the entire s matches the entire p
        return memory[0][0];
    }
};