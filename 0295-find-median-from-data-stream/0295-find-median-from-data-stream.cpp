class MedianFinder {
public:
    multiset<int>s;
    int size;
    MedianFinder() {
        size=0;
    }
    
    void addNum(int num) {
        s.insert(num);
        size++;
    }
    
    double findMedian() {
        double ans = 0;
        set<int>::iterator ptr = s.begin();
        if (size == 0) {
            return ans;
        }
        std::advance(ptr, size / 2);
        if (size % 2 == 1) {
            ans = *ptr;
        } else {
            ans += *ptr;
            std::advance(ptr, -1);
            ans += *ptr;
            ans /= 2;
        }
        return ans;
    }

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */