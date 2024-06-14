class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int>st;
        int n = nums.size();
        k++;
        for(int i = 0 ; i < min(k,n) ; i++){
            st.insert(nums[i]);
        }
        if(st.size()!=min(k,n))return true;
        for(int i = min(k,n) ; i < n ; i++){
            st.erase(nums[i-k]);
            st.insert(nums[i]);
            if(st.size()!=min(k,n))return true;
        }
        return false;
    }
};