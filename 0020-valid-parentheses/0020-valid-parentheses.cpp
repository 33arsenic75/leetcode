class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(char c:s){
            if(c=='(' || c=='{' || c=='[')stk.push(c);
            else if(stk.empty())return false;
            else if(c==')'){
                if (stk.top()=='(') stk.pop();
                else return false;
            }
            else if(c=='}'){
                if (stk.top()=='{') stk.pop();
                else return false;
            }
            else if(c==']'){
                if (stk.top()=='[') stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};