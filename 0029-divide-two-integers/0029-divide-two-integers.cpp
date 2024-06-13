#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }
        
        if (divisor == 1) {
            return std::min(std::max(dividend, INT_MIN), INT_MAX);
        }

        long longDividend = std::labs(static_cast<long>(dividend));
        long longDivisor = std::labs(static_cast<long>(divisor));
        
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long result = 0;

        while (longDividend >= longDivisor) {
            long tempDivisor = longDivisor;
            long multiple = 1;

            while (longDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            longDividend -= tempDivisor;
            result += multiple;
        }

        result *= sign;
        result = std::min(result, static_cast<long>(INT_MAX));
        result = std::max(result, static_cast<long>(INT_MIN));

        return static_cast<int>(result);
    }
};