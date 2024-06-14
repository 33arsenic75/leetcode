class Solution {
public:
    int time(vector<int>&a,vector<int>&b){
        return max(abs(a[0]-b[0]),abs(a[1]-b[1]));
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for( int i = 0 ; i < n-1 ; i++){
            ans+=time(points[i],points[i+1]);
        }
        return ans;
    }
};