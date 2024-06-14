class Solution {
public:
    int m1,m2,target;
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        m1=jug1Capacity,m2=jug2Capacity;
        target=targetCapacity;
        if(m1+m2>=target && target%gcd(m1,m2)==0)return true;
        return false;
    }
};