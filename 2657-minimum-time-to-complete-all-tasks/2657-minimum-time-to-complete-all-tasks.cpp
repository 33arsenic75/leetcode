class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        vector<bool>a(2001,false);
        sort(tasks.begin(), tasks.end(), [](vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        });
        for(vector<int>&v: tasks){
            int used = 0;
            for(int i = v[0] ; i <= v[1] ; i++){
                used += (int)a[i];
            }
            if(used>=v[2])continue;
            for(int i = v[1]; (i >= v[0]) && (used<v[2]) ; i--){
                if(a[i])continue;
                else{
                    a[i]=true;
                    used++;
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i <= 2001 ; i++)ans+=(int)a[i];
        return ans;
    }
};