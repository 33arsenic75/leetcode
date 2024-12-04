class Solution {
public:
    int dis(vector<int>&a,vector<int>&b){
        int ans = 0;
        ans += (a[0]-b[0])*(a[0]-b[0]);
        ans += (a[1]-b[1])*(a[1]-b[1]);
        return ans;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1==p2)return false;
        if(p1==p3)return false;
        if(p1==p4)return false;
        if(p2==p3)return false;
        if(p2==p4)return false;
        if(p3==p4)return false;

        set<int>dist;
        dist.insert(dis(p1,p2));
        dist.insert(dis(p1,p3));
        dist.insert(dis(p1,p4));
        dist.insert(dis(p2,p3));
        dist.insert(dis(p2,p4));
        dist.insert(dis(p3,p4));
        dist.erase(0);
        return dist.size()==2;
    }
};