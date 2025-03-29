class Solution {
public:
    const int MOD = 1e9 + 7;
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScores(n, 0);
        int maxElement = 0;
        for (int index = 0; index < n; index++) {
            maxElement = max(maxElement, nums[index]);
        }
        vector<int> primes = getPrimes(maxElement);
        for (int index = 0; index < n; index++) {
            int num = nums[index];
            for (int prime : primes) {
                if (prime * prime > num)
                    break;
                if (num % prime != 0)
                    continue;
                primeScores[index]++;
                while (num % prime == 0)
                    num /= prime;
            }
            if (num > 1) primeScores[index]++;
        }
        vector<int> nextDominant(n, n);
        vector<int> prevDominant(n, -1);
        stack<int> decreasingPrimeScoreStack;
        for (int index = 0; index < n; index++) {
            while (!decreasingPrimeScoreStack.empty() &&
                   primeScores[decreasingPrimeScoreStack.top()] <
                       primeScores[index]) {
                int topIndex = decreasingPrimeScoreStack.top();
                decreasingPrimeScoreStack.pop();
                nextDominant[topIndex] = index;
            }
            if (!decreasingPrimeScoreStack.empty())
                prevDominant[index] = decreasingPrimeScoreStack.top();
            decreasingPrimeScoreStack.push(index);
        }
        vector<long long> numOfSubarrays(n);
        for (int index = 0; index < n; index++) {
            numOfSubarrays[index] = (long long)(nextDominant[index] - index) *
                                    (index - prevDominant[index]);
        }
        vector<pair<int, int>> sortedArray(n);
        for (int index = 0; index < n; index++) {
            sortedArray[index] = {nums[index], index};
        }
        sort(sortedArray.begin(), sortedArray.end(), greater<>());
        long long score = 1;
        int processingIndex = 0;
        while (k > 0) {
            auto [num, index] = sortedArray[processingIndex++];
            long long operations = min((long long)k, numOfSubarrays[index]);
            score = (score * power(num, operations)) % MOD;
            k -= operations;
        }
        return score;
    }
private:
    long long power(long long base, long long exponent) {
        long long res = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                res = ((res * base) % MOD);
            }
            base = (base * base) % MOD;
            exponent /= 2;
        }
        return res;
    }
    vector<int> getPrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;
        for (int number = 2; number <= limit; number++) {
            if (!isPrime[number]) continue;
            primes.push_back(number);
            for (long long multiple = (long long)number * number;
                 multiple <= limit; multiple += number) {
                isPrime[multiple] = false;
            }
        }
        return primes;
    }
};