class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>x,y;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]){
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        int x_size = x.size();
        int y_size = y.size();
        nth_element(x.begin(), x.begin() + x_size/2, x.end());
        nth_element(y.begin(), y.begin() + y_size/2, y.end());
        int x_median = x[x_size/2];
        int y_median = y[y_size/2];
        int ans = 0;

        for(int x_cordinate: x){
            ans += abs(x_cordinate - x_median);
        }
        
        for(int y_cordinate: y){
            ans += abs(y_cordinate - y_median);
        }

        return ans;
    }
};