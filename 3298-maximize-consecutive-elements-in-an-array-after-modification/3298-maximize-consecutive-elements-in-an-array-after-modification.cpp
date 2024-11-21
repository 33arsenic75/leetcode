class Solution {
public:
    int maxSelectedElements(vector<int>& n) {
        map<int,int>mp;        
        sort(n.begin(),n.end());
        int ans = 0;
        for(int i: n){
            mp[i+1] = mp[i] + 1;
            mp[i] = mp[i-1] + 1;
            ans = max({ans,mp[i+1],mp[i]});
        }
        return ans;
    }
};

