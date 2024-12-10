class Solution {
public:
    int maximumLength(string s) {
        map<char,vector<int>>mp;
        char last = ' ';
        int count = 0;
        for(char c:s){
            if(c==last){
                count++;
            }
            else{
                mp[last].push_back(count);
                last = c;
                count = 0;
                count++;
            }
        }
        mp[last].push_back(count);
        for(int target = 50 ; target > 0 ; target --){
            for(int i = 0 ; i < 26 ; i++){
                char c = 'a'+i;
                int canmake = 0;
                cout<<c<<"\n";
                for(int len:mp[c]){
                    cout<<len<<" ";
                    canmake += max(0,len-target+1);
                }
                cout<<'\n';
                if(canmake>=3)return target;
            }
        }
        return -1;
    }
};