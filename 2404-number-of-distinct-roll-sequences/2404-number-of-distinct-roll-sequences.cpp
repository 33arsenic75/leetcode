class Solution {
public:

    int mod = 1e9 + 7;

    int dp[10000 + 1][7][7];

    int solve(int i, int j, int k, int n) {

        if(i == n) return 1;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int ans = 0;

        if(j == 0) {

            for(int l = 1; l <= 6; l++) {

                ans = (ans + solve(i + 1, l, k, n)) % mod;
            }
        
        }
        
        else if(k == 0) {

            for(int l = 1; l <= 6; l++) {

                if((__gcd(l, j) == 1) && (l != j)) {

                    ans = (ans + solve(i + 1, l, j, n)) % mod;
                
                }

            }
        }

        else {

            for(int l = 1; l <= 6; l++) {

                if((__gcd(l, j) == 1) && (l != j) && (l != k)) ans = (ans + solve(i + 1, l, j, n)) % mod;
            
            }

        }

        return dp[i][j][k] = ans;
    }
    
    int distinctSequences(int n) {

        //vector<vector<vector<int>>> dp (n, vector<vector<int>> (7, vector<int> (7, -1)));

        memset(dp, -1, sizeof dp);

        return solve(0, 0, 0, n);
        
    }
};