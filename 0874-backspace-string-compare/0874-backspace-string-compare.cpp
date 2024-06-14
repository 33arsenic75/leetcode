class Solution {
public:
    stack<char> func(string s){
        stack<char>stk;
        for(char c:s){
            if(c=='#'){
                if(!stk.empty())stk.pop();
            }
            else stk.push(c);
        }
        return stk;
    }
    bool backspaceCompare(string s, string t) {
        stack<char> t1=func(s),t2=func(t);
        return (t1==t2);
    }
};