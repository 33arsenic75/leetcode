/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    stack<int>st1;
    stack<int>st2;
    MinStack() {
        st1 = stack<int>();
        st2 = stack<int>();
    }
    
    void push(int val) {
        st1.push(val);
        if(st2.empty())st2.push(val);
        else if(st2.top()>=val)st2.push(val);
    }
    
    void pop() {
        if(st1.top()==st2.top())st2.pop();
        st1.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
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
// @lc code=end

