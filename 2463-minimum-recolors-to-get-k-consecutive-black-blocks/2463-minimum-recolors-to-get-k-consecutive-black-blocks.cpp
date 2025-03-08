class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        vector<int>colored(n,0);
        colored[0] = (blocks[0]=='W');
        for(int i = 1 ; i < n ; i++){
            colored[i] = colored[i-1] + (blocks[i]=='W');
        }
        int ans = colored[k-1];
        for(int i = k ; i < n ; i++){
            ans = min(ans, colored[i]-colored[i-k]);
        }
        return ans;
    }
};