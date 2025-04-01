class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long n = questions.size();
        vector<long long>ans(n,0);
        ans[n-1] = questions[n-1][0];
        long long best = ans[n-1];
        for(long long i = n-2 ; i >= 0 ; i--){
            ans[i] = ans[i+1];
            long long pts = questions[i][0];
            long long j = i + questions[i][1] + 1;
            if( j < n){
                ans[i] = max(ans[i], pts + ans[j]);
            }
            else{
                ans[i] = max(ans[i], pts);
            }
            best = max(best,ans[i]);
        }
        return best;
    }
};