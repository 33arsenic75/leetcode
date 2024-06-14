class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return (a[0] * a[0] + a[1] * a[1]) > (b[0] * b[0] + b[1] * b[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, decltype(&comp)> pq(comp);
        for(vector<int> i : points)pq.push(i);
        vector<vector<int>>ans;
        if(k > points.size())k=points.size();
        for(int i=0;i<k;i++){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};