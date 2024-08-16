class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int start = 0;
        map<string,int>mp;
        mp["RIGHT"]=1;
        mp["LEFT"]=-1;
        mp["UP"]=-n;
        mp["DOWN"]=n;
        for(string s:commands){
            start += mp[s];
        }
        return start;
    }
};