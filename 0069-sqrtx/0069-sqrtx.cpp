class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x; 
        
        int l = 0, h = x;
        while (l <= h) { 
            int m = l + (h - l) / 2;
            if (m <= x / m && (m + 1) > x / (m + 1)) 
                return m;
            else if (m < x / m) 
                l = m + 1;
            else
                h = m - 1;
        }
        return -1; 
    }
};
