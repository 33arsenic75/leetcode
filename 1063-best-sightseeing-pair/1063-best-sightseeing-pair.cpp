class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int>v1=values,v2=values;
        int n = values.size();
        for(int i = 0 ; i < n ; i++){
            v1[i] = i+v1[i];
            v2[i] = v2[i]-i;
        }
        int ans = 0;
        for(int i = n-2; i >= 0 ; i--){
            ans = max(ans,v1[i]+v2[i+1]);
            v2[i] = max(v2[i],v2[i+1]);
        }
        return ans;
    }
};