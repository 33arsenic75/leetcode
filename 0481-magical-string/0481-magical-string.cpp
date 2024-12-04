class Solution {
public:
    int magicalString(int n) {
        queue<int>q;
        q.push(2);
        int cnt=1;
        for(int i=2; i<n; ++i){
            int num=q.front();
            q.pop();
            if(num==1){
                cnt++;
            }
            int l;
            if(q.back()==2){
                l=1;
            }
            else{
                l=2;
            }
            for(int j=0; j<num; ++j){
                q.push(l);
            }
        }
        if(n==0){return 0;}
        return cnt;
    }
};