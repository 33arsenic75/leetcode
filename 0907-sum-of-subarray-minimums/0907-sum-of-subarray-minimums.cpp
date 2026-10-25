// using ll = long long;
// const ll MOD = (ll)(1e9) + 7;

// class Solution {
// public:
//     int n;
//     vector<int> a;
//     vector<int> tree;

//     void build(int v, int l, int r) {
//         if (l == r) {
//             tree[v] = l;
//             return;
//         }

//         int mid = l + (r - l) / 2;
//         build(2 * v + 1, l, mid);
//         build(2 * v + 2, mid + 1, r);

//         int left_idx = tree[2 * v + 1];
//         int right_idx = tree[2 * v + 2];

//         if (a[left_idx] < a[right_idx])
//             tree[v] = left_idx;
//         else
//             tree[v] = right_idx;
//     }

//     int query(int v, int l, int r, int ql, int qr) {
//         if (l == ql && r == qr)
//             return tree[v];

//         int mid = l + (r - l) / 2;

//         if (qr <= mid)
//             return query(2 * v + 1, l, mid, ql, qr);

//         if (ql > mid)
//             return query(2 * v + 2, mid + 1, r, ql, qr);

//         int left_ans = query(2 * v + 1, l, mid, ql, mid);
//         int right_ans = query(2 * v + 2, mid + 1, r, mid + 1, qr);

//         return a[left_ans] < a[right_ans] ? left_ans : right_ans;
//     }

//     int query(int l, int r) {
//         return query(0, 0, n - 1, l, r);
//     }

//     ll helper(int i, int j) {
//         if (i > j) return 0;

//         int min_idx = query(i, j);

//         ll left = min_idx - i + 1;
//         ll right = j - min_idx + 1;

//         ll ans = (left * right % MOD) * a[min_idx] % MOD;
//         ans = (ans + helper(i, min_idx - 1)) % MOD;
//         ans = (ans + helper(min_idx + 1, j)) % MOD;

//         return ans;
//     }

//     int sumSubarrayMins(vector<int>& arr) {
//         n = arr.size();
//         a = arr;
//         tree.assign(4 * n, -1);

//         build(0, 0, n - 1);

//         return helper(0, n - 1);
//     }
// };

using ll = long long;
const ll MOD = (ll)(1e9) + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> st;
        st.reserve(n);

        ll ans = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() &&
                   (i == n || arr[st.back()] >= arr[i])) {
                int idx = st.back();
                st.pop_back();

                int left = st.empty() ? idx + 1 : idx - st.back();
                int right = i - idx;

                ans = (ans + (ll)arr[idx] * left % MOD * right) % MOD;
            }

            st.push_back(i);
        }

        return ans;
    }
};