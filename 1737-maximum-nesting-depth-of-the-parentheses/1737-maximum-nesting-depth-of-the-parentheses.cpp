class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int temp = 0;
        for(char c:s){
            if(c=='(')temp++;
            else if(c==')')temp--;
            ans = max(ans,temp);
        }
        return ans;
    }
};