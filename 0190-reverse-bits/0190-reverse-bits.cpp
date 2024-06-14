class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 0, j = 31;
        while( i < j){
            if (((n >> i) & 1) != ((n >> j) & 1)) {
                // Swap bits i and j
                n ^= (1 << i);
                n ^= (1 << j);
            }
            i++;
            j--;
        }
        return n;
    }
};