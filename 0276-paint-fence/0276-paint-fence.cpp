class Solution {
public:
    int numWays(int n, int k) {
        int prevOnes = k;
        int prevTwos = 0;

        for (int i = 1; i < n; i++) {
            int numTwos = prevTwos;
            int numOnes = prevOnes;

            prevOnes = (numOnes + numTwos) * (k - 1);
            prevTwos = numOnes;
        }

        return prevOnes + prevTwos;

    }           

};