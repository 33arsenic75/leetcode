#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int n;
    int target;
    vector<int> cand;

    void help(vector<int> temp, int i, int sum) {
        if (i == n && sum == target) {
            ans.push_back(temp);
            return;
        }
        if (i == n || sum > target) return;
        temp.push_back(cand[i]);
        help(temp, i, sum + cand[i]);
        temp.pop_back();
        help(temp, i + 1, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        this->target = target;
        cand = candidates;
        help(vector<int>(), 0, 0);
        return ans;
    }
};
