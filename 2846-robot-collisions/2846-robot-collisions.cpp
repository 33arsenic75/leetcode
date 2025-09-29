#include <bits/stdc++.h>
using namespace std;

struct rob {
    int pos;
    int hel;
    char dir;
    int idx;
    bool operator<(const rob &other) const {
        return pos < other.pos;
    }
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<rob> a(n);

        for (int i = 0; i < n; i++) {
            a[i].pos = positions[i];
            a[i].hel = healths[i];
            a[i].dir = directions[i];
            a[i].idx = i;
        }

        sort(a.begin(), a.end());

        stack<int> st; // will store indices of robots moving 'R'
        vector<rob> alive;

        for (int i = 0; i < n; i++) {
            if (a[i].dir == 'R') {
                st.push(i);
            } else { // dir == 'L'
                while (!st.empty() && a[i].hel > 0) {
                    int j = st.top();
                    if (a[j].hel == a[i].hel) {
                        // both destroyed
                        a[j].hel = 0;
                        a[i].hel = 0;
                        st.pop();
                        break;
                    } else if (a[j].hel < a[i].hel) {
                        // right one destroyed
                        a[j].hel = 0;
                        a[i].hel--;
                        st.pop();
                    } else {
                        // left one destroyed
                        a[i].hel = 0;
                        a[j].hel--;
                        break;
                    }
                }
            }
        }

        // Collect survivors
        for (int i = 0; i < n; i++) {
            if (a[i].hel > 0) {
                alive.push_back(a[i]);
            }
        }

        // restore original order
        sort(alive.begin(), alive.end(), [](const rob &x, const rob &y) {
            return x.idx < y.idx;
        });

        vector<int> res;
        for (auto &r : alive) res.push_back(r.hel);
        return res;
    }
};
