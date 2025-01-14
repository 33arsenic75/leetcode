class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefixCommonArray(n), frequency(n + 1, 0);
        int commonCount = 0;
        for (int currentIndex = 0; currentIndex < n; ++currentIndex) {
            if (++frequency[A[currentIndex]] == 2) ++commonCount;
            if (++frequency[B[currentIndex]] == 2) ++commonCount;
            prefixCommonArray[currentIndex] = commonCount;
        }
        return prefixCommonArray;
    }
};