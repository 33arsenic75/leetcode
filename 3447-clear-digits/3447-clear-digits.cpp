class Solution {
public:
    string clearDigits(string s) {
        int answerLength = 0;
        for (int charIndex = 0; charIndex < s.size(); charIndex++) {
            if (isdigit(s[charIndex])) {
                answerLength = max(answerLength - 1, 0);
            } else {
                s[answerLength++] = s[charIndex];
            }
        }
        s.resize(answerLength);
        return s;
    }
};