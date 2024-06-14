class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int idx = 0;
        int n = popped.size();
        for (int i : pushed) {
            stk.push(i);
            // cout << "Pushed: " << i << endl;
            while (!stk.empty() && stk.top() == popped[idx]) {
                // cout << "Popped: " << stk.top() << endl;
                stk.pop();
                idx++;
            }
        }
        return idx == n;
    }
};