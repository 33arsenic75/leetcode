class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i:nums)mp[i]++;
        vector<pair<int,int>>frq;
        for(pair<int,int>x:mp)frq.push_back({x.second,x.first});
        sort(frq.rbegin(),frq.rend());
        vector<int>ans;
        if(frq.size()<k)k=frq.size();
        for(int i=0;i<k;i++){
            ans.push_back(frq[i].second);
        }
        return ans;
    }
};