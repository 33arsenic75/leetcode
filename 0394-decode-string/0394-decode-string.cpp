class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int numberOfTimes = 0;
        string decodedString;
        for(auto &ch : s){
            string str(1,ch);
            if(isdigit(ch))
                numberOfTimes = (numberOfTimes*10) + (ch -'0'); 
            else if(ch=='['){
                if(numberOfTimes > 0)
                    st.push(to_string(numberOfTimes));
                numberOfTimes = 0;
                st.push(str);
            }
            else if(ch==']'){
                string temp;
                while(st.top()!="["){
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                int noOfTimes = stoi(st.top());  
                st.pop();
                string res ; 
                for(int k=0;k<noOfTimes;k++)
                    res += temp;
                st.push(res);
            }
            else{
                if(st.empty() || isdigit(st.top()[0]) || st.top()=="[")
                    st.push(str);
                else{
                    string temp = st.top();
                    st.pop();
                    temp += ch;
                    st.push(temp);
                }
            }
        }
        while(!st.empty()){
            decodedString = st.top() + decodedString;
            st.pop();
        }
        return decodedString;
    }
};