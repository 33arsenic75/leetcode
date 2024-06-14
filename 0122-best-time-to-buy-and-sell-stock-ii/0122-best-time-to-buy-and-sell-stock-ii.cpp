// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int ans = 0;
//         for(int i = 0; i<n-1; i++){
//             ans+=max(0,prices[i+1]-prices[i]);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        pair<int,int>p={INT_MIN,0};
        for(int i = 0; i<n; i++){
            p = { max(p.first,p.second - prices[i]), max(p.second,p.first + prices[i])};
        }
        return p.second;
    }
};