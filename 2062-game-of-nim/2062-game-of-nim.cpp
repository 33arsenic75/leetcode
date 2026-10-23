class Solution {
public:
    bool nimGame(vector<int>& piles) {
        return accumulate(piles.begin(), piles.end(), 0, [](int a, int b){return a^b;});
    }
};