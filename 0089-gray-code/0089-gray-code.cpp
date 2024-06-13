class Solution {
public:
    int n;
    int gray(int n) {
        return n ^ (n >> 1);
    }
    vector<int> grayCode(int n) {
        this->n=n;
        int size=1<<n;
        vector<int>v(size);
        cout<<size;
        for(int i=0;i<size;i++){
            v[i]=gray(i);
        }
        return v;
    }
};