class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n= cars.size();
        vector<double> ans(n,-1.0);
        stack<int> s;
        for(int i = n-1 ; i >= 0 ; i--){
            while(!s.empty()){
                if((cars[i][1] <= cars[s.top()][1])) s.pop();
                else{
                    int next = s.top();
                    double time = ((double)(cars[next][0] - cars[i][0])) / (cars[i][1]-cars[next][1]);
                    if((ans[next]!=-1.0) && (time>ans[next])) {
                        s.pop();
                    }
                    else {
                        ans[i] = time; 
                        break;
                    }
                }
            }
            s.push(i);
        }
        return ans;
    }
};