class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int countPairs(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int temp = mid + 1;

        for (int i = left; i <= mid; i++) {
            while (temp <= right && (long long)nums[i] > 2LL * nums[temp]) {
                temp++;
            }

            count += temp - (mid + 1);
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return 0;
        }

        int mid = left + (right - left) / 2;
        int count = 0;

        count += mergeSort(nums, left, mid);
        count += mergeSort(nums, mid + 1, right);
        count += countPairs(nums, left, mid, right);

        merge(nums, left, mid, right);

        return count;
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1);

        int i = left;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        while (j <= right) {
            temp[k++] = nums[j++];
        }

        for (int x = 0; x < temp.size(); x++) {
            nums[left + x] = temp[x];
        }
    }
};