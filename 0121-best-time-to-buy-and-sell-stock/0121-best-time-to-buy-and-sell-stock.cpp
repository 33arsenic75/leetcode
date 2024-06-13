class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentmin = prices[0];
        int maxPro = 0;
        for(int i = 1;i<prices.size();i++){
            currentmin = min(currentmin,prices[i]);
            maxPro= max(maxPro,prices[i]-currentmin);
        }
        return maxPro;

    }
};