class Solution {
public:
    long countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }

private:
    long atLeastK(string word, int k) {
        long numValidSubstrings = 0;
        int start = 0;
        int end = 0;
        unordered_map<char, int> vowelCount;
        int consonantCount = 0;
        while (end < word.length()) {
            char newLetter = word[end];
            if (isVowel(newLetter)) {
                vowelCount[newLetter]++;
            } else {
                consonantCount++;
            }
            while (vowelCount.size() == 5 and consonantCount >= k) {
                numValidSubstrings += word.length() - end;
                char startLetter = word[start];
                if (isVowel(startLetter)) {
                    if (--vowelCount[startLetter] == 0) {
                        vowelCount.erase(startLetter);
                    }
                } else {
                    consonantCount--;
                }
                start++;
            }
            end++;
        }
        return numValidSubstrings;
    }
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};