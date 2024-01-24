class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;st.push(-1);
        int ans=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='(')st.push(i);
            else{
                st.pop();
                if(!st.empty()){
                    int j=st.top();
                    ans=max(ans,i-j);
                }
                else{
                    st.push(i);
                }
                
            }
        }
        return ans;
    }
};