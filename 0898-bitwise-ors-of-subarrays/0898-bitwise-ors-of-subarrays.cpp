class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> all;
        vector<int> prev, curr;

        all.reserve(arr.size() * 10);

        for (int n : arr) {
            curr.clear();
            curr.push_back(n);

            for (int x : prev) {
                int val = x | n;
                if (curr.back() != val)
                    curr.push_back(val);
            }

            for (int x : curr)
                all.insert(x);

            prev.swap(curr);
        }

        return all.size();
    }
};