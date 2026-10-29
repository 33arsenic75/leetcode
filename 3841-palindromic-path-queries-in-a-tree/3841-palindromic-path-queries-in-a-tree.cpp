#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define py cout << "YES\n"
#define pn cout << "NO\n"
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << " = " << x << endl
#define show1(v)                                                               \
  for (auto i : v)                                                             \
  cout << i << ' '
#define show(v)                                                                \
  show1(v);                                                                    \
  cout << '\n'
#else
#define debug(x)
#endif
const ll INF = 1e9;
const ll LINF = INF * INF;

template <typename T> class Segmenttree {
public:
  int sz;
  vector<T> t;
  Segmenttree() {}
  Segmenttree(const vector<T> &a) : sz(a.size()), t(2 * a.size()) {
    for (int i = 0; i < sz; i++) t[sz + i] = a[i];
    for (int i = sz - 1; i > 0; i--) t[i] = (t[2 * i] ^ t[2 * i + 1]);
  }
  void range_update(int p, int, T val) { // point set
    for (t[p += sz] = val; p > 1; p >>= 1) t[p >> 1] = (t[p] ^ t[p ^ 1]);
  }
  T range_query(int l, int r) { // inclusive [l, r]
    T res = 0;
    for (l += sz, r += sz + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = (res ^ t[l++]);
      if (r & 1) res = (res ^ t[--r]);
    }
    return res;
  }
};

template <class T, bool VALS_IN_EDGES> class HLD {
private:
  ll N, R, tim = 0; // n, root node, time
  vector<vector<ll>> adj;
  vector<ll> par, siz, depth, rt,
      pos;                // parent, size, depth, root, position arrays
  Segmenttree<T> segtree; // Modify as needed

  void dfs_sz(ll v) {
    if (par[v] != -1)
      adj[v].erase(find(adj[v].begin(), adj[v].end(), par[v]));
    for (ll &u : adj[v]) {
      par[u] = v, depth[u] = depth[v] + 1;
      dfs_sz(u);
      siz[v] += siz[u];
      if (siz[u] > siz[adj[v][0]])
        swap(u, adj[v][0]);
    }
  }

  void dfs_hld(ll v) {
    pos[v] = tim++;
    for (ll u : adj[v]) {
      rt[u] = (u == adj[v][0] ? rt[v] : u);
      dfs_hld(u);
    }
  }

  template <class B> void process(ll u, ll v, B op) {
    for (; rt[u] != rt[v]; v = par[rt[v]]) {
      if (depth[rt[u]] > depth[rt[v]])
        swap(u, v);
      op(pos[rt[v]], pos[v]);
    }
    if (depth[u] > depth[v])
      swap(u, v);
    op(pos[u] + VALS_IN_EDGES, pos[v]);
  }

public:
  HLD(const vector<vector<ll>> &adj_, ll _Root, const vector<T> &base_)
      : N(adj_.size()), R(_Root), adj(adj_), par(N, -1), siz(N, 1), depth(N),
        rt(N), pos(N) // modify if need
  {
    rt[R] = _Root;
    dfs_sz(R);
    dfs_hld(R);
    setsegtree(base_);                                  // CHANGED: build the segtree
  }

  T query_path(ll u, ll v) {
    T res = 0; // default value, modify depending on problem
    process(u, v, [&](ll l, ll r) {
      res ^= segtree.range_query(l, r);                 // CHANGED: xor instead of max
    });
    return res;
  }
  void setsegtree(const vector<T> &base) {
    vector<T> temp(base.size());
    for (ll i = 0; i < base.size(); i++)
      temp[pos[i]] = base[i];
    segtree = Segmenttree<T>(temp);
  }
  void modify_node(ll u, T val) { segtree.range_update(pos[u], pos[u], val); }

  void modify_subtree(ll v, T val) {
    segtree.range_update(pos[v] + VALS_IN_EDGES, pos[v] + siz[v] - 1, val);
  }
};


class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<ll>>adj(n);                       // CHANGED: ll to match HLD
        for(vector<int>&e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<ll>base(n, 0);                           // CHANGED: ll to match HLD
        for(int i = 0 ; i < n ; i++){
            base[i] |= (1LL<<(s[i]-'a'));
        }

        HLD<ll,false> hld(adj, 0, base);
        vector<bool>ans;                                // CHANGED: only "query" results go here

        for (string &q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                ll u; char c;
                ss >> u >> c;
                hld.modify_node(u, 1LL << (c - 'a'));
            } else {
                ll u, v;
                ss >> u >> v;
                ll mask = hld.query_path(u, v);
                ans.push_back(__builtin_popcountll(mask) <= 1);
            }
        }
        return ans;
    }
};