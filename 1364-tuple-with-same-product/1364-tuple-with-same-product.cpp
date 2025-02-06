class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int numsLength = nums.size();
        unordered_map<int, int> pairProductsFrequency;
        int totalNumberOfTuples = 0;
        for (int firstIndex = 0; firstIndex < numsLength; firstIndex++) {
            for (int secondIndex = firstIndex + 1; secondIndex < numsLength;
                 secondIndex++) {
                pairProductsFrequency[nums[firstIndex] * nums[secondIndex]]++;
            }
        }
        for (auto [productValue, productFrequency] : pairProductsFrequency) {
            int pairsOfEqualProduct = (productFrequency - 1) * productFrequency / 2;
            totalNumberOfTuples += 8 * pairsOfEqualProduct;
        }

        return totalNumberOfTuples;
    }
};