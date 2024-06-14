class MyQueue {
public:
    stack<int>st1,st2;
    MyQueue() {
    }
    void transfer(){
        int temp;
        while(!st1.empty()){
            temp = st1.top();
            st1.pop();
            st2.push(temp);
        }
    }
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty())transfer();
        int temp = st2.top();
        st2.pop();
        return temp;
    }
    
    int peek() {
        if(st2.empty())transfer();
        return st2.top();
    }
    
    bool empty() {
        if(st2.empty())transfer();
        return st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */