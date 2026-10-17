class Solution {
public:
    int sumdigits(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    bool compare(int a, int b) {
        int sum1 = sumdigits(a);
        int sum2 = sumdigits(b);

        if (sum1 < sum2) return true;
        if (sum1 > sum2) return false;
        return a < b;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> sorted(n);
        for (int i = 0; i < n; i++) {
            sorted[i] = {nums[i], i};
        }

        sort(sorted.begin(), sorted.end(),
             [&](const auto& a, const auto& b) {
                 return compare(a.first, b.first);
             });

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || sorted[i].second == i)
                continue;

            int cycle = 0;
            int j = i;

            while (!vis[j]) {
                vis[j] = true;
                j = sorted[j].second;
                cycle++;
            }

            ans += cycle - 1;
        }

        return ans;
    }
};