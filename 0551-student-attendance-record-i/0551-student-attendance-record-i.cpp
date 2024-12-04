class Solution {
public:
    bool checkRecord(string s) {
        int cnt = count(s.begin(),s.end(),'A');
        if(cnt>=2)return false;
        cnt = 0;
        for(char c:s){
            if(c=='L')cnt++;
            else{
                cnt=0;
            }
            if(cnt==3)return false;
        }   
        return true;
    }
};