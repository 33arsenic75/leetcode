class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>mp;
        for(int i:nums)mp[i]++;
        int ans = 0;
        for(pair<int,int>p:mp){
            if(p.second<2)return -1;
            ans += (p.second-1)/3 + 1;
        }
        return ans;
    }
};
/// 1 2 3 4 5 6 7 8 
/// 3n+2 -> n + 1
/// 3n+1 -> n + 1
/// 3n -> n
/// x -> (x-1)/3 + 1
