class DinnerPlates {
 public:
  DinnerPlates(int capacity) : capacity(capacity) {
    minHeap.push(0);
  }

  void push(int val) {
    const int index = minHeap.top();
    if (index == stacks.size())
      stacks.push_back({});
    stacks[index].push(val);
    if (stacks[index].size() == capacity) {
      minHeap.pop();
      if (minHeap.empty())
        minHeap.push(stacks.size());
    }
  }

  int pop() {
    // Remove empty stacks from the back.
    while (!stacks.empty() && stacks.back().empty())
      stacks.pop_back();
    if (stacks.empty())
      return -1;
    return popAtStack(stacks.size() - 1);
  }

  int popAtStack(int index) {
    if (index >= stacks.size() || stacks[index].empty())
      return -1;
    if (stacks[index].size() == capacity)
      minHeap.push(index);
    const int val = stacks[index].top();
    stacks[index].pop();
    return val;
  }

 private:
  const int capacity;
  vector<stack<int>> stacks;
  priority_queue<int, vector<int>, greater<>> minHeap;
};