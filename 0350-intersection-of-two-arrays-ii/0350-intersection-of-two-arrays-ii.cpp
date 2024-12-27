class Solution {
public:
    vector<int> intersect(vector<int>& n1, vector<int>& n2) {
        sort(n1.begin(), n1.end());
        sort(n2.begin(), n2.end());
        vector<int> res;
        int i = 0, j = 0;
        while (i < n1.size() && j < n2.size()) {
            if (n1[i] < n2[j]) {
                i++;
            } else if (n1[i] > n2[j]) {
                j++;
            } else {
                res.push_back(n1[i]);
                i++;j++;
            }
        }
        return res;
    }
};
