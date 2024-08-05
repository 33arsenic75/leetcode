class Solution {
public:
    vector<int>p;
    int minv(int i,int j){
        if(j<i)return 1e9;
        return *min_element(p.begin()+i,p.begin()+j+1);
    }
    int maxv(int i,int j){
        if(j<i)return 0;
        return *max_element(p.begin()+i,p.begin()+j+1);
    }
    int ans(int i,int j){
        if(j<=i)return 0;
        int mid = i + (j-i)/2;
        int result = 0;
        result = max(result,ans(i,mid));
        result = max(result,ans(mid+1,j));
        result = max(result,maxv(mid+1,j)-minv(i,mid));
        return result;
    }
    int maxProfit(vector<int>& prices) {
        p = prices;
        return ans(0,p.size()-1);
    }
};