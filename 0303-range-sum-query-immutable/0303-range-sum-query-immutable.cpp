class NumArray {
public:
    vector<int>pre;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        pre=vector<int>(n+1,0);
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return pre[right+1]-pre[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */