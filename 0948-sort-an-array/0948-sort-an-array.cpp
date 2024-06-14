#include <vector>
using namespace std;

class Solution {
public:
    void mysort(vector<int>& a, int i, int j) {
        if (i < j) {
            int mid = i + (j - i) / 2;
            mysort(a, i, mid);
            mysort(a, mid + 1, j);
            merge(a, i, mid, mid + 1, j);
        }
    }

    void merge(vector<int>& a, int s1, int l1, int s2, int l2) {
        vector<int> temp;
        int i = s1, j = s2;
        while (i <= l1 && j <= l2) {
            if (a[i] <= a[j]) {
                temp.push_back(a[i++]);
            } else {
                temp.push_back(a[j++]);
            }
        }
        while (i <= l1) temp.push_back(a[i++]);
        while (j <= l2) temp.push_back(a[j++]);

        for (int k = s1; k <= l2; ++k) {
            a[k] = temp[k - s1];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mysort(nums, 0, nums.size() - 1);
        return nums;
    }
};
