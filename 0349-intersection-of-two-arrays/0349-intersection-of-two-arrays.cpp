#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        
        while (i < n && j < m) {
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                int temp = nums1[i];
                while (i < n && nums1[i] == temp) i++;
                temp = nums2[j];
                while (j < m && nums2[j] == temp) j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return ans;
    }
};
