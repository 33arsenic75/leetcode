class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int length = colors.size();
        int result = 0;
        int alternatingElementsCount = 1;
        int lastColor = colors[0];
        for (int i = 1; i < length + k - 1; i++) {
            int index = i % length;
            if (colors[index] == lastColor) {
                alternatingElementsCount = 1;
                lastColor = colors[index];
                continue;
            }
            alternatingElementsCount += 1;
            if (alternatingElementsCount >= k) {
                result++;
            }
            lastColor = colors[index];
        }
        return result;
    }
};