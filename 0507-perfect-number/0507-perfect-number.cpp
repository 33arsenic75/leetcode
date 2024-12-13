class Solution {
public:
    bool checkPerfectNumber(int num) {
        int i = 1;
        int sum = 0;
        for(i = 1 ; i*i < num ; i ++){
            if(num%i==0){
                sum += i + (num/i);
            }
        }
        if(i*i==num)sum+=i;
        return sum==2*num;
    }
};