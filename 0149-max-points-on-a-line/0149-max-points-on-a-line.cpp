
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> mp;
            int duplicates = 0;
            int best = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }

                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                // Normalize the sign.
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                string key = to_string(dx) + "," + to_string(dy);
                best = max(best, ++mp[key]);
            }

            ans = max(ans, best + duplicates + 1);
        }

        return ans;
    }
};
