class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1));
        if (k > total) return "";
        string result(n, 'a');
        unordered_map<char, char> nextSmallest = {{'a', 'b'}, {'b', 'a'}, {'c', 'a'}};
        unordered_map<char, char> nextGreatest = {{'a', 'c'}, {'b', 'c'}, {'c', 'b'}};
        int startA = 1;
        int startB = startA + (1 << (n - 1));
        int startC = startB + (1 << (n - 1));
        if (k < startB) {
            result[0] = 'a';
            k -= startA;
        } 
        else if (k < startC) {
            result[0] = 'b';
            k -= startB;
        } 
        else {
            result[0] = 'c';
            k -= startC;
        }
        for (int charIndex = 1; charIndex < n; charIndex++) {
            int midpoint = (1 << (n - charIndex - 1));
            if (k < midpoint) {
                result[charIndex] = nextSmallest[result[charIndex - 1]];
            } 
            else {
                result[charIndex] = nextGreatest[result[charIndex - 1]];
                k -= midpoint;
            }
        }
        return result;
    }
};