class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& bld) {
        int n = bld.size();
        multiset<int> st;
        st.insert(0);                         // ground level, so the set is never empty
        vector<vector<int>> v(2*n, vector<int>(2, 0));

        for (int i = 0; i < n; i++) {
            v[2*i][0]   = bld[i][0];          // start: negative height
            v[2*i][1]   = -bld[i][2];

            v[2*i+1][0] = bld[i][1];          // end: positive height
            v[2*i+1][1] = bld[i][2];
        }
        sort(v.begin(), v.end());

        vector<vector<int>> ans;
        int prev = 0;
        for (vector<int>& a : v) {
            if (a[1] < 0) st.insert(-a[1]);
            else st.erase(st.find(a[1]));

            int cur = *st.rbegin();           // current max height
            if (cur != prev) {                // only record when the skyline changes
                ans.push_back({a[0], cur});
                prev = cur;
            }
        }
        return ans;
    }
};