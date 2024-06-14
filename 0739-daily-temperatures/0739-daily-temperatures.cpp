class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n=a.size();
        vector<int>ans(n,0);
        stack<pair<int,int>>stk;
        for(int i=n-1;i>=0;i--){
            if(stk.empty()){
                stk.push({a[i],i});
                ans[i]=0;
            }
            else if(a[i]>=stk.top().first){
                while(!stk.empty() && a[i]>=stk.top().first)stk.pop();
                if(stk.empty())ans[i]=0;
                else ans[i]=stk.top().second-i;
                stk.push({a[i],i});
            }
            else{
                ans[i]=1;
                stk.push({a[i],i});
            }
        }
        return ans;
    }
};