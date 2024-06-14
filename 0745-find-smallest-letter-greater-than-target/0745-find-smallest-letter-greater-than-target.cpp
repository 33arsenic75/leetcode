class Solution {
public:
    int help(char c){
        return c-'a';
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        int t = target -'a';
        for(char c:letters){
            if(help(c)>t)return c;
        }
        return letters[0];
    }
};