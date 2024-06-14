class Solution {
public:
    int kthFactor(int n, int k) {
        int counter = 0;
        vector<int> left, right;
        for (int i = 1; i <= sqrt(n); i++) {
            if (i == sqrt(n)) {
                left.push_back(i);
                continue;
            }
            if (n % i == 0) {
                left.push_back(i);
                right.push_back(n / i);
            }
        }
        // O(sqrt(n))
        reverse(right.begin(), right.end());
        left.insert(left.end(), right.begin(), right.end());
        return k - 1 < left.size() ? left[k - 1] : -1;
    }
};