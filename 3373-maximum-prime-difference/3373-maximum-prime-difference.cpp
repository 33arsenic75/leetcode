class Solution {
public:
    bool isprime(int n){
        if(n==1)return false;
        for(int i = 2 ; i*i <= n ; i++){
            if(n%i==0)return false;
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n;
        for(int i = 0 ; i < n ; i++){
            if(isprime(nums[i])){
                start = i;
                break;
            }
        }
        for(int i = n-1 ; i >=0 ; i--){
            if(isprime(nums[i])){
                end = i;
                break;
            }
        }
        cout<<start<<" "<<end<<'\n';
        return end-start;
    }
};