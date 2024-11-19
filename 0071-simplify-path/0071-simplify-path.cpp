class Solution {
public:
    string simplifyPath(string path) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        stack<string>st;
        stringstream s(path);
        string x;
        getline(s,x,'/');
        while(getline(s,x,'/')) {
            if(x=="" || x=="." || (x==".." && st.empty())) continue;
            else if(x==".." && !st.empty()) st.pop();
            else st.push(x);
        }
        string ans;
        if(st.empty()) ans += "/";
        while(!st.empty()) {
            string tp = st.top();
            st.pop();
            reverse(tp.begin(), tp.end());
            ans += tp + '/';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};