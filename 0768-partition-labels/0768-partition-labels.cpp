class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>mp;
        int n = s.size();
        for(int i = 0; i < n ; i++)mp[s[i]]=i;
        vector<int>sz;
        int last = -1, mx = 0;
        for(int i = 0 ; i < n ; i++){
            mx = max(mx, mp[s[i]]);
            if(mx == i){
                sz.push_back(i-last);
                last = i;
            }
        }
        return sz;
    }
};