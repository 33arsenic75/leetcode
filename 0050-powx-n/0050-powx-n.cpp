class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        
        double result = 1;
        long long absN = abs((long long)n);
        
        while (absN > 0) {
            if (absN % 2 == 1) {
                result *= x;
            }
            x *= x;
            absN /= 2;
        }
        
        return n < 0 ? 1 / result : result;
    }
};
