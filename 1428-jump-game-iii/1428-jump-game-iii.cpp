class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool>reach(n,false);
        vector<int>visit(n,-1);
        for(int i = 0 ; i < n ; i++)reach[i]=(arr[i]==0);
        function<bool(int)>it = [&](int at){
            if(visit[at]!=-1)return reach[at];
            visit[at] = true;
            if(at+arr[at]<n){
                it(at+arr[at]);
                reach[at]  = reach[at] || reach[at+arr[at]];
            }
            if(at-arr[at]>=0){
                it(at-arr[at]);
                reach[at] = reach[at] || reach[at-arr[at]];
            }
            return reach[at];
        };
        it(start);
        return reach[start];
    }
};