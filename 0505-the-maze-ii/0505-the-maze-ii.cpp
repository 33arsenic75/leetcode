class Solution {
public:
    int n, m;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    vector<vector<int>> g;

    bool inrange(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    bool iswall(int i, int j) {
        return g[i][j] == 1;
    }

    void move(int& i, int& j, int dir) {
        while (true) {
            int i_ = i + dx[dir];
            int j_ = j + dy[dir];

            if (inrange(i_, j_) && !iswall(i_, j_)) {
                i = i_;
                j = j_;
            } else {
                return;
            }
        }
    }

    int distance(int i1, int j1, int i2, int j2) {
        return abs(i1 - i2) + abs(j1 - j2);
    }

    int shortestDistance(vector<vector<int>>& maze,
                         vector<int>& start, vector<int>& end) {
        g = maze;
        n = g.size();
        m = g[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        dist[start[0]][start[1]] = 0;
        pq.push({0, start[0], start[1]});

        while (!pq.empty()) {
            auto [d, i, j] = pq.top();
            pq.pop();

            if (d != dist[i][j]) continue;

            if (i == end[0] && j == end[1]) return d;

            for (int k = 0; k < 4; k++) {
                int i_ = i, j_ = j;
                move(i_, j_, k);

                int nd = d + distance(i, j, i_, j_);

                if (nd < dist[i_][j_]) {
                    dist[i_][j_] = nd;
                    pq.push({nd, i_, j_});
                }
            }
        }

        return -1;
    }
};