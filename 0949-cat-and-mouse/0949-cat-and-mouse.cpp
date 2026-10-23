class Solution {
    static constexpr int DRAW = 0;
    static constexpr int MOUSE = 1;
    static constexpr int CAT = 2;

public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        int N = n * n * 2;

        // State: (mouse * n + cat) * 2 + turn
        // turn = 0: mouse's turn; turn = 1: cat's turn
        vector<int> color(N, DRAW);
        vector<int> degree(N, 0);
        queue<int> q;

        auto id = [n](int m, int c, int t) {
            return (m * n + c) * 2 + t;
        };

        for (int m = 0; m < n; ++m) {
            for (int c = 1; c < n; ++c) {
                degree[id(m, c, 0)] = graph[m].size();

                for (int v : graph[c]) {
                    if (v != 0) ++degree[id(m, c, 1)];
                }
            }
        }

        // Mouse reaches hole 0.
        for (int c = 1; c < n; ++c) {
            for (int t = 0; t < 2; ++t) {
                int s = id(0, c, t);
                color[s] = MOUSE;
                q.push(s);
            }
        }

        // Cat catches mouse.
        for (int m = 1; m < n; ++m) {
            for (int t = 0; t < 2; ++t) {
                int s = id(m, m, t);
                color[s] = CAT;
                q.push(s);
            }
        }

        while (!q.empty()) {
            int s = q.front();
            q.pop();

            int t = s & 1;
            int p = s >> 1;
            int c = p % n;
            int m = p / n;
            int winner = color[s];

            int pt = t ^ 1;

            auto update = [&](int pm, int pc) {
                int ps = id(pm, pc, pt);
                if (color[ps] != DRAW) return;

                // Previous player can move to a state they win.
                if ((pt == 0 && winner == MOUSE) ||
                    (pt == 1 && winner == CAT)) {
                    color[ps] = winner;
                    q.push(ps);
                } else {
                    // This move loses; decrement remaining legal moves.
                    if (--degree[ps] == 0) {
                        color[ps] = (pt == 0 ? CAT : MOUSE);
                        q.push(ps);
                    }
                }
            };

            if (pt == 0) {
                // Previous turn was the mouse's.
                for (int pm : graph[m])
                    update(pm, c);
            } else {
                // Previous turn was the cat's.
                for (int pc : graph[c]) {
                    if (pc != 0)
                        update(m, pc);
                }
            }
        }

        return color[id(1, 2, 0)];
    }
};