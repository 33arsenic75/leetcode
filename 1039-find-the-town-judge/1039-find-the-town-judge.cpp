class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>> v(n + 1, make_pair(0, 0)); // Adjust the vector size and indexing

        // Count the trust relationships
        for (int i = 0; i < trust.size(); i++) {
            v[trust[i][0]].first++;
            v[trust[i][1]].second++;
        }

        // Find the person who has received trust from all others
        for (int i = 1; i <= n; i++) { // Start the loop from 1
            if (v[i].first == 0 && v[i].second == n - 1) {
                return i;
            }
        }

        return -1; // If no such person exists
    }
};
