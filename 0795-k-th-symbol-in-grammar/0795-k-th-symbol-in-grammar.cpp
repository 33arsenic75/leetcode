class Solution {
public:
    int kthGrammar(int n, int k) {
        return fnc(n,k);
    }
    int fnc(int n,int k){
        cout<<n<<' '<<k<<endl;
        if(n==1)return 0;
        else if(k<=(1<<(n-2)))return fnc(n-1,k);
        else return 1-fnc(n-1,k-(1<<(n-2)));
    }
};