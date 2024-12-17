class Solution {
public:
    int minSteps(string s, string t) {
        // Step 1: Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        int i = 0, j = 0;       // Pointers for strings `s` and `t`
        int op = 0;             // Operations counter
        
        // Step 2: Compare characters in sorted order
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {  // Characters match
                i++; j++;
            } 
            else if (s[i] < t[j]) {  // Character in `s` is smaller
                op++;  // Delete character in `s`
                i++;
            } 
            else {  // Character in `t` is smaller
                op++;  // Delete character in `t`
                j++;
            }
        }
        
        // Step 3: Handle remaining characters in `s` and `t`
        op += (s.size() - i);  // Remaining characters in `s`
        op += (t.size() - j);  // Remaining characters in `t`
        
        return op;
    }
};
