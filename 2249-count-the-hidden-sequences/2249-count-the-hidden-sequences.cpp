class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long curr = 0, minn = 0, maxx = 0;
        for(int n: differences){
            curr += n;
            minn = min(curr, minn);
            maxx = max(curr, maxx);
        }
        maxx += lower - minn;
        return max(upper - maxx+1,0ll);
    }
};