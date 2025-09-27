#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> 
using ordered_multiset = tree<T, null_type, less_equal<T>, 
                              rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
            a[i] = nums1[i] - nums2[i];

        long long ans = 0;
        ordered_multiset<int> s;

        for (int i = n - 1; i >= 0; i--) {
            // we need count of elements >= a[i] - diff
            int val = a[i] - diff;
            int smaller = s.order_of_key(val); // elements < val
            int total = s.size();
            ans += (total - smaller);

            s.insert(a[i]);
        }
        return ans;
    }
};
