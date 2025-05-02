class Solution {
public:
    string pushDominoes(string dom) {
        int n = dom.size();
        vector<int>ldis(n,n+1),rdis(n+1);
        int last = -(n+1);
        for(int i = 0 ; i < n ; i++){
            if(dom[i] == 'R'){
                last = i;
                rdis[i] = 0;
            }
            else if(dom[i] == '.'){
                rdis[i] = i - last;
            }
            else{
                last = -(n+1);
            }
        }
        last = 2*n;
        for(int i = n-1 ; i >= 0 ; i--){
            if(dom[i] == 'L'){
                last = i;
                ldis[i] = 0;
            }
            else if(dom[i] == '.'){
                ldis[i] = last - i;
            }
            else{
                last = 2*n;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(min(ldis[i],rdis[i]) > n)continue;
            else if(ldis[i] == rdis[i])continue;
            else if(ldis[i] < rdis[i])dom[i] = 'L';
            else dom[i] = 'R';
        }
        return dom;
    }
};