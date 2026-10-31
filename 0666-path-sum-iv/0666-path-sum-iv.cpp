class Solution {
public:
    int pathSum(vector<int>& nums) {
        int n = nums.size();
        int d = *max_element(nums.begin(), nums.end());
        d /= 100;

        vector<vector<int>> tree(d+1);
        vector<vector<int>> sz(d+1);
        vector<vector<int>> ans(d+1);

        for(int i = 0; i < d; i++) {
            tree[i+1].assign((1 << i), -1);
            sz[i+1].assign((1 << i), 0);
            ans[i+1].assign((1 << i), 0);
        }

        for(int num: nums) {
            int depth = num/100;
            int pos = (num/10)%10;
            int val = num%10;

            tree[depth][pos-1] = val;
        }

        function<bool(int, int)> inrange = [&](int depth, int pos) {
            if(depth < 1 || depth > d) return false;
            return pos >= 0 && pos < (1 << (depth-1));
        };

        // sz = number of leaf descendants
        // ans = sum of path sums from this node to its leaf descendants
        function<void(int, int)> sz_helper = [&](int depth, int pos) {
            if(!inrange(depth, pos) || tree[depth][pos] == -1)
                return;

            int l = 2*pos;
            int r = 2*pos+1;

            bool left = inrange(depth+1, l) &&
                        tree[depth+1][l] != -1;

            bool right = inrange(depth+1, r) &&
                         tree[depth+1][r] != -1;

            if(!left && !right) {
                sz[depth][pos] = 1;
                ans[depth][pos] = tree[depth][pos];
                return;
            }

            if(left) sz_helper(depth+1, l);
            if(right) sz_helper(depth+1, r);

            sz[depth][pos] = sz[depth+1][l] * left
                           + sz[depth+1][r] * right;

            ans[depth][pos] = tree[depth][pos] * sz[depth][pos]
                            + (left ? ans[depth+1][l] : 0)
                            + (right ? ans[depth+1][r] : 0);
        };

        sz_helper(1, 0);

        return ans[1][0];
    }
};