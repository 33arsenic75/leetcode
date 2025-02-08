class NumberContainers {
public:
    NumberContainers() {}
    void change(int index, int number) {
        indexToNumbers[index] = number;
        numberToIndices[number].push(index);
    }
    int find(int number) {
        if (numberToIndices.find(number) == numberToIndices.end()) {
            return -1;
        }
        auto& minHeap = numberToIndices[number];
        while (!minHeap.empty()) {
            int index = minHeap.top();
            if (indexToNumbers[index] == number) {
                return index;
            }
            minHeap.pop();
        }
        return -1;
    }
private:
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numberToIndices;
    unordered_map<int, int> indexToNumbers;
};
