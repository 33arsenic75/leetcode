class MinStack {
public:
    stack<int>stk;
    stack<int>mstk;
    MinStack() { 
        mstk.push(INT_MAX);
    }
    
    void push(int val) {
        stk.push(val);
        if(val<=mstk.top())mstk.push(val);
    }
    
    void pop() {
        if(stk.top()==mstk.top())mstk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mstk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */