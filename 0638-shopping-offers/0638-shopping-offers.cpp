class Solution {
public:
    void newSpecial(vector<int>& price, vector<vector<int>>& special){
        for(int i = 0; i < price.size(); i++){
            vector<int> newSpecial(price.size() + 1, 0);
            newSpecial[i] = 1;
            newSpecial[newSpecial.size() - 1] = price[i];
            special.push_back(newSpecial);
        }
    }

    int amountLeft(vector<int>& needs){
        int amountNeeded = accumulate(needs.begin(), needs.end(), 0);
        return amountNeeded;
    }

    void choose(vector<int>& choice, vector<int>& needs, int decision, int& currCost){
        for(int i = 0; i < needs.size(); i++){
            needs[i] = needs[i] - choice[i] * decision;
        }
        currCost = currCost + choice[choice.size() - 1] * decision;
    }

    bool isValidChoice(vector<int>& choice, vector<int>& needs) {
        for (int i = 0; i < needs.size(); i++) {
            if (choice[i] > needs[i]) {
                return false;
            }
        }
        return true;
    }

    void helper(vector<vector<int>>& special, vector<int>& needs, int& minCost, int currCost, int index){
        if (index == special.size()) {
            if (amountLeft(needs) == 0) {
                minCost = min(minCost, currCost);
            }
            return;
        }

        if(isValidChoice(special[index], needs)){ 
            choose(special[index], needs, 1, currCost);
            helper(special, needs, minCost, currCost, index);
            choose(special[index], needs, -1, currCost);
        }

        helper(special, needs, minCost, currCost, index + 1);
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int minCost = INT_MAX;
        int currCost = 0;
        newSpecial(price, special);
        helper(special, needs, minCost, currCost, 0);
        return minCost;
    }
};