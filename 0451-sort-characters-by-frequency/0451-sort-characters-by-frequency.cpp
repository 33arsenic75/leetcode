class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>>a(128,{0,0});
        for(char c:s){
            a[c-0]={a[c-0].first+1,c};
        }
        sort(a.rbegin(), a.rend());  // Sort in descending order
        string ss = "";
        for(pair<int,char> p : a){
            ss += string(p.first, p.second);
        }
        return ss;
    }
};