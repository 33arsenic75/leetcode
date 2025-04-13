class Solution {
public:
    const long long mod = 1e9 + 7;

    long long exp(long long base, long long pow){
        if(pow == 0) return 1;
        else if(pow & 1){
            return (base % mod * exp(base, pow - 1) % mod) % mod;
        }
        else {
            long long half = exp(base, pow / 2);
            return (half * half) % mod;
        }
    }

    int countGoodNumbers(long long n) {
        long long even_positions = (n + 1) / 2;
        long long odd_positions = n / 2;

        long long result = (exp(5, even_positions) * exp(4, odd_positions)) % mod;
        return result;
    }
};
