class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        int n = rooms.size();
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            
            for (int j : rooms[i]) {
                if (!visited[j]) {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        
        return true;
    }
};
