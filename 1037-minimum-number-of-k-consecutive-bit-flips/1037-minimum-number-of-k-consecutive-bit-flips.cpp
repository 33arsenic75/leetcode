class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>cnt(n+1,0);
        int operations = 0;
        int ans = 0;
        for(int i = 0 ; i <= n-k ; i++){
            operations += cnt[i];
            operations%=2;
            if((operations^nums[i])==0){
                cnt[i]++;
                cnt[i+k]++;
                ans++;
                operations++;
            }
        }
        for(int i = n-k+1 ; i < n ; i++){
            operations+=cnt[i];
            operations%=2;
            if((operations^nums[i])==0)return -1;
        }
        return ans;
    }
};