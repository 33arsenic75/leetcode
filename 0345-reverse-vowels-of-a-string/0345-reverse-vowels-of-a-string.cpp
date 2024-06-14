class Solution {
public:
    bool isvowel(char c){
        return (c=='a') || (c=='e') || (c=='i') || (c=='o') || (c=='u') || (c=='A') || (c=='E') || (c=='I') || (c=='O') || (c=='U');
    }
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        while(i<j){
            if(isvowel(s[i])&&isvowel(s[j])){
                swap(s[i],s[j]);
                i++;j--;
            }
            else if(isvowel(s[i]))j--;
            else if(isvowel(s[j]))i++;
            else{
                i++;
                j--;
            }
        }
        return s;
        
    }
};