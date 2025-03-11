class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        vector<int> lastPos = {-1, -1, -1};
        int total = 0;
        for (int pos = 0; pos < len; pos++) {
            lastPos[s[pos] - 'a'] = pos;
            total += 1 + min({lastPos[0], lastPos[1], lastPos[2]});
        }

        return total;
    }
};