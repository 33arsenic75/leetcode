class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int count = 0; // Initialize the count of stretchy words
        
        // Iterate over each word in the list
        for (const string& word : words) {
            // Check if the current word is stretchy compared to the target string `s`
            if (isStretchy(word, s))
                count++; // Increment the count if it is stretchy
        }
        
        return count; // Return the total count of stretchy words
    }
    
private:
    bool isStretchy(const string& word, const string& target) {
        int i = 0, j = 0; // Pointers to track positions in `word` and `target`
        
        // Iterate through both strings until one is exhausted
        while (i < word.size() && j < target.size()) {
            
            // If characters at the current position don't match, the word can't be stretchy
            if (word[i] != target[j]) return false;
            
            int len1 = 1, len2 = 1; // Length of consecutive character groups
            
            // Count the length of the current group in `word`
            while (i + 1 < word.size() && word[i] == word[i + 1]) {
                i++;
                len1++;
            }
            
            // Count the length of the current group in `target`
            while (j + 1 < target.size() && target[j] == target[j + 1]) {
                j++;
                len2++;
            }
            
            // Check if the group in `word` can be stretched to match the group in `target`
            // 1. len1 > len2: word has more characters than allowed by the target, return false
            // 2. len1 < len2 && len2 < 3: target group is too short to allow stretching, return false
            if (len1 > len2 || (len1 < len2 && len2 < 3)) return false;
            i++;
            j++;
        }
        
        // Check if both strings have been fully processed
        return i == word.size() && j == target.size();
    }
};