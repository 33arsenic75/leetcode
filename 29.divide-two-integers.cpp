/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int div(int a, int b, int sum){
        if( a < b )return sum;
        int low = 0, high = a;
        int mid = 0;
        while(low<high){
            mid = low + (high - low)/2;
            if( b * (1<<mid) > a){
                high = mid - 1;
            }
            else if ( b* (1<<mid) < a){
                low = mid + 1;
            }
            else break;
        }
        return div(a - b*(1<<mid), b , sum + (1<<mid));

    }
    int divide(int dividend, int divisor) {
        return div(abs(dividend),abs(divisor),0);
    }
};
// @lc code=end

