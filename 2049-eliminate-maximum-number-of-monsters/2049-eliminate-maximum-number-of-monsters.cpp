class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<float> time(n);
        for (int i = 0; i < n; i++) {
            time[i] = (float)dist[i] / speed[i];
        }
        sort(time.begin(), time.end());
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (time[i] > i)cnt++;    
            else break; 
        }        
        return cnt;
    }
};
