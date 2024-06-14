class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        long long n=position.size();
        vector<pair<long long,long long>>v(n);
        for(long long i=0;i<n;i++)v[i].first=position[i];
        for(long long i=0;i<n;i++)v[i].second=speed[i];
        sort(v.begin(),v.end());
        long long fleet=n;
        for(long long i=n-2;i>=0;i--){
            long long p0=v[i].first,p1=v[i+1].first;
            long long s0=v[i].second,s1=v[i+1].second;
            if(s1*(target-p0) <= s0*(target-p1)){
                v[i]=v[i+1];
                fleet--;
            }
        }
        return fleet;

    }
};