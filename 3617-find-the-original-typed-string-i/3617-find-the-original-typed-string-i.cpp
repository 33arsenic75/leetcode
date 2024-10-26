class Solution {
public:
    int possibleStringCount(string word) {
        char last = '1';
        int count = 1;
        int n = word.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(word[i]==last)count++;
            else{
                last = word[i];
                ans+=count;
                count = 0;
            }
        }
        ans+=count;
        return ans;
    }
};