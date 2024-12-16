#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1, q2; // Member variables for the two queues

    MyStack() {
        // Constructor: No need to initialize q1 and q2 explicitly.
    }
    
    void push(int x) {
        q1.push(x); // Push to the primary queue
    }
    
    int pop() {
        // Transfer all elements except the last one from q1 to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topElement = q1.front(); // The last element in q1 is the "top" of the stack
        q1.pop(); // Remove the top element
        
        // Swap q1 and q2 to make q2 the primary queue
        swap(q1, q2);
        
        return topElement;
    }
    
    int top() {
        // Transfer all elements except the last one from q1 to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topElement = q1.front(); // The last element in q1 is the "top" of the stack
        
        // Move the last element to q2 as well
        q2.push(topElement);
        q1.pop();
        
        // Swap q1 and q2 to make q2 the primary queue
        swap(q1, q2);
        
        return topElement;
    }
    
    bool empty() {
        return q1.empty(); // q1 being empty means the stack is empty
    }
};
