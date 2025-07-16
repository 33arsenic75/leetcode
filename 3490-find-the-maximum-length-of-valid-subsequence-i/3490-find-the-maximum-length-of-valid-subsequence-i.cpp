class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++)nums[i] %= 2;
        int lo = -1;
        int lz = -1;
        int z = 0, o = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0){
                lz = i;
                z++;
            }
            else{
                lo = i;
                o++;
            }
        }
        if(lo == -1 || lz == -1)return max(z,o);
        int llo = 0, llz = 0;
        for(int i = max(lo,lz); i >= 0 ; i--){
            if(nums[i] == 0){
                llz = llo + 1;
            }
            else{
                llo = llz + 1;
            }
        }

        return max(max(llo,llz),max(z,o));
    }
};