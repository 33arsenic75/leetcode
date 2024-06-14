class Solution {
public:
    vector<int> ans;
    
    int getMaximumGenerated(int n) {
        if (n == 0) return 0; // Edge case for n=0
        
        ans = vector<int>(n+1, 0);
        ans[0] = 0;
        ans[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            if (i % 2 == 0) {
                ans[i] = ans[i / 2];
            } else {
                ans[i] = ans[i / 2] + ans[i / 2 + 1];
            }
        }
        
        return *max_element(ans.begin(), ans.end());
    }
};
