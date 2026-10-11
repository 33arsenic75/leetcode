class HitCounter {
public:
    deque<int>dq;
    HitCounter() {
    }

    void clean(int timestamp){
        while(!dq.empty()){
            if(dq.front() <= timestamp - 300)dq.pop_front();
            else return;
        }
    }
    void hit(int timestamp) {
        dq.push_back(timestamp);
        clean(timestamp);        
    }
    
    int getHits(int timestamp) {
        clean(timestamp);  
        return dq.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */