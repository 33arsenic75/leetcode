class Solution {
public:
    int maximizeGreatness(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0;
        for (int& a : A)
            if (a > A[res])
                res++;
        return res;
    }
};