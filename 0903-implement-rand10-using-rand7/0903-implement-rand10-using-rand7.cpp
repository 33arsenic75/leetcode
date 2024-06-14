// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int i = rand7();
        int j = rand7();
        if(i>2 || j>5)return rand10();
        if(i==2)j+=5;
        return j;
    }
};