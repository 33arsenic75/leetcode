class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int prev = 0;
        double taxes = 0;
        for (const auto& bracket : brackets){
            int upper = bracket[0];
            int rate = bracket[1];
            if (income > prev){
                int taxableIncome = min(income, upper) - prev;
                taxes += taxableIncome * (rate / 100.0);
                prev = upper;
            } if (income <= upper){
                break;
            }
        }
        return taxes;
    }
};
