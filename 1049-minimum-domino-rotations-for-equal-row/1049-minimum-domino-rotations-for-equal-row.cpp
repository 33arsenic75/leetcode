class Solution {
public:
    static int minDominoRotations(vector<int>& T, vector<int>& B) {
        const int n=T.size();
        bitset<8> X=255;
        for(int i=0; i<n; i++){
            X &=(1<<T[i])|(1<<B[i]);
        }
        if (X==0) return -1;
        vector<int> cand;
        for(int i=1; i<=6; i++)
            if (X[i]) cand.push_back(i);
        int x=cand[0];
        int swapT=0, swapB=0;
        for(int i=0; i<n; i++){
            if (T[i]!=x) swapT++;
            if (B[i]!=x) swapB++;
        }
        return min(swapT, swapB);
    }
};