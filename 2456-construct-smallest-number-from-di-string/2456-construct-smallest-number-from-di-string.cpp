class Solution {
public:
    string smallestNumber(string pattern) {
        int patternLength = pattern.length();
        int maxSoFar = 0, currMax = 0, temp;
        vector<int> arrD(patternLength + 1, 0);
        for (int patternIndex = patternLength - 1; patternIndex >= 0;
             patternIndex--) {
            if (pattern[patternIndex] == 'D')
                arrD[patternIndex] = arrD[patternIndex + 1] + 1;
        }
        string result = "";
        for (int position = 0; position <= patternLength; position++) {
            if (pattern[position] == 'I') {
                maxSoFar++;
                result += '0' + maxSoFar;
                maxSoFar = max(maxSoFar, currMax);
                currMax = 0;
            } else {
                temp = 1 + maxSoFar + arrD[position];
                result += '0' + temp;
                currMax = max(currMax, temp);
            }
        }
        return result;
    }
};