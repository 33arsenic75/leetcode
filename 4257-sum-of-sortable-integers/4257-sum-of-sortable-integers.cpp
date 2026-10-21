class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> drops;  // j with nums[j] > nums[j + 1]
        for (int j = 0; j + 1 < n; j++)
            if (nums[j] > nums[j + 1]) drops.push_back(j);

        auto sortable = [&](int k) {  // each drop needs its own block, which must wrap into order and fit between its neighbors
            if ((int)drops.size() > n / k) return false;  // a block holds at most one drop
            int prev_block = -1, prev_drop = -1;
            for (int j : drops) {
                int block = j / k, offset = j % k;
                int start = j - offset, end = start + k - 1;
                if (offset == k - 1  // the drop sits on a border
                        || block == prev_block  // a second drop in the same block
                        || nums[end] > nums[start]  // the block can't wrap into order
                        || (start && (prev_block == block - 1 ? nums[prev_drop] : nums[start - 1]) > nums[j + 1])  // left block's max > this block's min
                        || (end + 1 < n && nums[j] > nums[end + 1]))  // this block's max > the next value
                    return false;
                prev_block = block, prev_drop = j;
            }
            return true;
        };

        vector<int> divisors;
        for (int k = 1; k * k <= n; k++)
            if (n % k == 0) {
                divisors.push_back(k);
                if (k != n / k) divisors.push_back(n / k);
            }
        auto good = divisors | views::filter(sortable);
        return accumulate(good.begin(), good.end(), 0);
    }
};