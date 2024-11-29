class Solution {
public:
    int dig(int n){
        int sum = 0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int differenceOfSum(vector<int>& nums) {
        int digsum = 0, elemsum = 0;
        for(int n:nums){
            digsum+=dig(n);
            elemsum+=n;
        }
        return abs(digsum-elemsum);
    }
};