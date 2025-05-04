class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int>mp;
        int ans = 0;
        for(vector<int>&v: dominoes){
            int sum = v[0] + v[1];
            int prod = v[0] * v[1];
            ans += mp[{sum,prod}];
            mp[{sum,prod}]++;
        }
        return ans;
    }
};