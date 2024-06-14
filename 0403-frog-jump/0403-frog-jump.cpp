class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<int,set<int>>mp;
        mp[0]={0};
        set<int>temp;
        for(int i:stones){
            temp = mp[i];
            for(int j:temp){
                if(j-1>0)mp[i+j-1].insert(j-1);
                mp[i+j].insert(j);
                mp[i+j+1].insert(j+1);
            }
            if(!mp[stones[n-1]].empty())return true;
        }
        return false;
    }
};