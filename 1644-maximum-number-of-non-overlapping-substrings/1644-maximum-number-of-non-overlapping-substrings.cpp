#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> beg(26, n), end(26, -1);
        
        // record the first and last occurrence of each character
        for (int i = 0; i < n; i++) {
            beg[s[i] - 'a'] = min(beg[s[i] - 'a'], i);
            end[s[i] - 'a'] = max(end[s[i] - 'a'], i);
        }

        // expand intervals so that they contain all characters fully
        for (int c = 0; c < 26; c++) {
            if (beg[c] == n) continue;
            int l = beg[c], r = end[c];
            for (int i = l; i <= r; i++) {
                l = min(l, beg[s[i] - 'a']);
                r = max(r, end[s[i] - 'a']);
            }
            beg[c] = l;
            end[c] = r;
        }

        // collect all valid substrings (minimal intervals)
        vector<pair<int,int>> intervals;
        for (int c = 0; c < 26; c++) {
            if (beg[c] == n) continue;
            bool valid = true;
            for (int i = beg[c]; i <= end[c]; i++) {
                if (beg[s[i]-'a'] < beg[c] || end[s[i]-'a'] > end[c]) {
                    valid = false;
                    break;
                }
            }
            if (valid) intervals.push_back({end[c], beg[c]});
        }

        
        sort(intervals.begin(), intervals.end());

        
        vector<string> ans;
        int lastEnd = -1;
        for (auto [r, l] : intervals) {
            if (l > lastEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                lastEnd = r;
            }
        }
        return ans;
    }
};
