class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int>r ; 
        queue<int>d ; 
        int n = s.length() ; 
        for(int i = 0 ; i < n ; i++){
            (s[i] == 'R') ? r.push(i) : d.push(i) ;
        }
        while(!r.empty() && !d.empty()){
            int x , y ; 
            x = r.front(); 
            y = d.front(); 
            r.pop() ; 
            d.pop() ; 
            (x < y) ? r.push(n + x) : d.push(n + y) ; 
        }
        return !r.empty() ? "Radiant" : "Dire" ; 
    }
};