class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            int temp = x;
            x = y;
            y = temp;
            reverse(s.begin(), s.end());
        }

        int aCount = 0, bCount = 0, totalPoints = 0;

        for (int i = 0; i < s.size(); ++i) {
            char currentChar = s[i];

            if (currentChar == 'a') {
                ++aCount;
            } else if (currentChar == 'b') {
                if (aCount > 0) {
                    --aCount;
                    totalPoints += x;
                } else {
                    ++bCount;
                }
            } else {
                totalPoints += min(bCount, aCount) * y;
                aCount = bCount = 0;
            }
        }
        totalPoints += min(bCount, aCount) * y;

        return totalPoints;
    }
};