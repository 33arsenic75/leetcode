#include <vector>
using namespace std;

class CustomStack {
public:
    vector<int> stk;
    int idx;
    int max;
    CustomStack(int maxSize) {
        stk = vector<int>(maxSize, -1);
        idx = 0;
        max = maxSize;
    }

    void push(int x) {
        if (idx == max)
            return; // Stack is full, cannot push
        stk[idx] = x;
        idx++;
    }

    int pop() {
        if (idx == 0)
            return -1; // Stack is empty
        idx--;
        return stk[idx];
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(k, idx); i++) {
            stk[i] += val;
        }
    }
};


