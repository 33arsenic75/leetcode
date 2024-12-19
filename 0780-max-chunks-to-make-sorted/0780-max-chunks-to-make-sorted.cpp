class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        int n = a.size();
        int mx = -1;
        int chunks = 0;
        for(int i = 0 ; i < n ; i++){
            mx = max(mx,a[i]);
            if(i==mx)chunks++;
        }
        return chunks;
    }
};