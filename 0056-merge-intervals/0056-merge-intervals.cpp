class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& itv) {
        int n = itv.size();
        vector<vector<int>>ans;
        sort(itv.begin(), itv.end());
        int i = 0;
        while(i < n){
            int j = i;
            int max_left = itv[i][1];
            while(j < n){
                if(itv[j][0] <= max_left){
                    max_left = max(max_left, itv[j][1]);
                    j++;
                }
                else{
                    break;
                }
            }
            vector<int>tmp = {itv[i][0], max_left};
            ans.push_back(tmp);
            i = j;
        }
        return ans;
    }
};