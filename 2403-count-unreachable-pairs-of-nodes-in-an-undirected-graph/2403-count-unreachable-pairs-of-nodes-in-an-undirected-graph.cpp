
class Solution {
public:

    vector<long long >v;
    vector<long long >s;
    long long head(long long i){
        while(v[i]!=i)i=v[i];
        return i;
    }
    void merge(long long i,long long j){
        long long h1=head(i);
        long long h2=head(j);
        if(h1==h2)return;
        ///cout<<h1<<' '<<s[h1]<<endl;
        ///cout<<h2<<' '<<s[h2]<<endl;
        if(s[h1]<=s[h2]){
            v[h1]=h2;
            s[h2]+=s[h1];
        }
        else{
            v[h2]=h1;
            s[h1]+=s[h2];
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        v=vector<long long >(n);
        s=vector<long long >(n,1);
        for(long long i=0;i<n;i++){
            v[i]=i;
        }
        for(vector<int>v:edges){
            merge(v[0],v[1]);
        }
        long long sum=0,perfect=0;
        for(long long i=0;i<n;i++){
            if(v[i]==i){
                sum+=s[i];
                perfect+=s[i]*s[i];
            }
        }
        return (sum * sum - perfect) / 2;
    }
};