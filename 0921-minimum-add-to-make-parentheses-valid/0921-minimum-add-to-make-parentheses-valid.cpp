class Solution {
public:
    int minAddToMakeValid(string s) {
        int sum = 0;
        int ans = 0;

        for(char c : s) {
            if(c == '(') {
                sum++;
            } else {
                sum--;
                if(sum < 0) {
                    ans++;
                    sum = 0;
                }
            }
        }

        return ans + sum;
    }
};