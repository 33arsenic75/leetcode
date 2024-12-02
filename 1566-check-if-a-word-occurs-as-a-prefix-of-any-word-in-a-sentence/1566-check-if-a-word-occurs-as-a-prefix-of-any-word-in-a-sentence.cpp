class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int space = 1;
        int i = 0;
        int n = searchWord.size();
        bool waiting = false;
        for(char c:sentence){
            if(c==' '){
                space++;
                i = 0;
                waiting = false;
            }
            else if(c==searchWord[i] && !waiting){
                i++;
                if(i==n)return space;
            }
            else{
                waiting = true;
            }
        }
        return -1;
    }
};