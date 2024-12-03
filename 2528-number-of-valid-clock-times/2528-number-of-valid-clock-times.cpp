class Solution {
public:
    int countTime(string time) {
        vector<int> perm;
        if (time[0] == '?') {
            if (time[1] != '?' && time[1]-48<=3) perm.push_back(3);
            else if (time[1] != '?' && time[1]-48>=4) perm.push_back(2);
            else if (time[1] == '?') perm.push_back(24);
        }
        if (time[1] == '?') {
            if (time[0] != '?' && time[0]-48<=1) perm.push_back(10);
            else if (time[0] != '?' && time[0]-48==2) perm.push_back(4);
        }
        if (time[3] == '?') perm.push_back(6);
        if (time[4] == '?') perm.push_back(10);
        
        int ans = 1;
        for (auto x:perm) ans*=x;

        return ans;
    }
    
    
};