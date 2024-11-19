// class Solution {
// public:
//     string countAndSay(int n) {
//         if(n==1){
//             return "1";
//         }
//         string ans;
//         string s = countAndSay(n-1) + " ";
//         int cnt = 1;
//         char c = s[0];
//         for(int i = 1 ; i < s.size() ; i++){
//             if(s[i]==c){
//                 cnt++;
//             }
//             else{
//                 ans += to_string(cnt) + c;
//                 c = s[i];
//                 cnt = 1;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string countAndSay(int n) {
        vector<string>ans(n+1);
        ans[1]="1";
        for(int i = 2; i <= n ; i++){
            string result;
            string s = ans[i-1] + " ";
            int cnt = 1;
            char c = s[0];
            for(int i = 1 ; i < s.size() ; i++){
                if(s[i]==c){
                    cnt++;
                }
                else{
                    result += to_string(cnt) + c;
                    c = s[i];
                    cnt = 1;
                }
            }
            ans[i] = result;
        }
        return ans[n];
    }
};

