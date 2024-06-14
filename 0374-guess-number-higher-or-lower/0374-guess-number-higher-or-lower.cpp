/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int low,high,g,res;
    int guessNumber(int n) {
        low = 1, high = n;
        while(true){
            g = low + (high-low)/2;
            res = guess(g);
            if(res==0)return g;
            else if(res<0)high = g - 1;
            else low = g + 1;
        }
        return n;
    }
};