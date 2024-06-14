class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        stones.push_back(0);
        priority_queue pq(stones.begin(),stones.end());
        while(pq.size()>1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(x!=y)pq.push(y-x);
        }
        return pq.top();
    }
};