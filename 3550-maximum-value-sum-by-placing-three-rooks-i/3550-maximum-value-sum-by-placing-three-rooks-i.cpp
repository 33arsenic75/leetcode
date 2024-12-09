#define ll long long
class Solution {
    ll dp[101][101][101];
private:
    ll solve(int ind, int firstCol, int secondCol, vector<vector<pair<ll, ll>>>& arr){
        if(ind == arr.size()) return -1e18;
        
        if(dp[ind][firstCol + 1][secondCol + 1] != -1) return dp[ind][firstCol + 1][secondCol + 1];

        ll ans = LLONG_MIN;
        if(firstCol == -1){
            ans = max(ans, solve(ind + 1, firstCol, secondCol, arr)); //not take case
            //take case - top 3 elements possibilities
            ans = max(ans, arr[ind][0].first + solve(ind + 1, arr[ind][0].second, secondCol, arr));
            ans = max(ans, arr[ind][1].first + solve(ind + 1, arr[ind][1].second, secondCol, arr));
            ans = max(ans, arr[ind][2].first + solve(ind + 1, arr[ind][2].second, secondCol, arr));
        }
        else if(secondCol == -1){
            ans = max(ans, solve(ind + 1, firstCol, secondCol, arr)); //not take case
            //take case WITH 1 RESTRICTION
            if(arr[ind][0].second != firstCol){
                ans = max(ans, arr[ind][0].first + solve(ind + 1, firstCol, arr[ind][0].second, arr));
            }
            if(arr[ind][1].second != firstCol){
                ans = max(ans, arr[ind][1].first + solve(ind + 1, firstCol, arr[ind][1].second, arr));
            }
            if(arr[ind][2].second != firstCol){
                ans = max(ans, arr[ind][2].first + solve(ind + 1, firstCol, arr[ind][2].second, arr));
            }
        }
        else{
            ans = max(ans, solve(ind + 1, firstCol, secondCol, arr)); //not take case
            //take case WITH 2 RESTRICTIONS
            if(arr[ind][0].second != firstCol && arr[ind][0].second != secondCol){
                ans = max(ans, arr[ind][0].first); //no more recursion calls as 3 rooks have been placed
            }
            if(arr[ind][1].second != firstCol && arr[ind][1].second != secondCol){
                ans = max(ans, arr[ind][1].first); //no more recursion calls as 3 rooks have been placed
            }
            if(arr[ind][2].second != firstCol && arr[ind][2].second != secondCol){
                ans = max(ans, arr[ind][2].first); //no more recursion calls as 3 rooks have been placed
            }
        }

        return dp[ind][firstCol + 1][secondCol + 1] = ans;
    }
public:
    ll maximumValueSum(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<pair<ll, ll>>> arr;

        for(int i = 0; i < n; i++){
            vector<pair<ll, ll>> temp;
            for(int j = 0; j < m; j++){
                temp.push_back({board[i][j], j});
            }
            sort(temp.rbegin(), temp.rend());
            arr.push_back(temp);
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, -1, -1, arr);
    }
};