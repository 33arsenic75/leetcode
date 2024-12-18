class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> st; // Monotonic stack to store indices of prices

        for (int i = n - 1; i >= 0; i--) {
            // Maintain the stack such that it only contains elements greater than the current price
            while (!st.empty() && prices[st.top()] > prices[i]) {
                st.pop();
            }

            // If the stack is not empty, the top of the stack is the next smaller or equal price
            ans[i] = prices[i] - (st.empty() ? 0 : prices[st.top()]);

            // Push the current index onto the stack
            st.push(i);
        }

        return ans;
    }
};
