class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int ans = 0;
        for (int x : arr1) {
            auto it1 = lower_bound(arr2.begin(), arr2.end(), x - d);
            auto it2 = upper_bound(arr2.begin(), arr2.end(), x + d);

            if (it1 == it2) ans++;
        }

        return ans;
    }
};