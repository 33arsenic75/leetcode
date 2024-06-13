class Solution {
public:
    void rec(int i,int prev, int tar, vector<int>& ans, vector<int>& c,
             vector<vector<int>>& st) {

        
        if (i >= c.size()) {
            if (tar == 0) {
                st.push_back(ans);
            }
            return;
        }

        if (c[i] <= tar) {
            prev=c[i];
            ans.push_back(c[i]);
            rec(i + 1,prev, tar - c[i], ans, c, st);
            ans.pop_back();
        }
        int j=i;
        while(j<c.size() && c[i]==c[j]){
            j++;
        }
        rec(j,prev, tar, ans, c, st);
        
    }

    vector<vector<int>> combinationSum2(vector<int>& c, int tar) {
        int n = c.size();
        vector<vector<int>> ans;
        sort(c.begin(),c.end());

        vector<vector<int>> st;
        vector<int> v;

        rec(0,-1, tar, v, c, st);

        for (auto it : st) {
            ans.push_back(it);
        }

        return ans;
    }
};