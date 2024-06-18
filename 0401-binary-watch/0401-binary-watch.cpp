class Solution {
public:
    string hour(int n){
        return to_string(n);
    }
    string minute(int n){
        string s = to_string(n);
        if(s.size()==1)s = "0"+s;
        return s;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        map<int,vector<string>>hr;
        map<int,vector<string>>min;
        for(int i = 0 ; i < 60 ; i++){
            int one = __builtin_popcount(i);
            if( one <= turnedOn){
                min[one].push_back(minute(i));
            }
        }
        for(int i = 0 ; i <= 11 ; i++){
            int one = __builtin_popcount(i);
            if( one <= turnedOn){
                hr[one].push_back(hour(i));
            }
        }
        for(int i = 0 ; i <= turnedOn ; i++){
            int j = turnedOn - i;
            for(string&h:hr[i]){
                for(string&mn:min[j]){
                    ans.push_back(h+":"+mn);
                }
            }
        }
        return ans;
    }
};