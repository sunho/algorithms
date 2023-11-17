#include <bits/stdc++.h>
#include <iterator>

using namespace std;

using ll = long long;

template <typename Info> struct seg_tree {
  int n;
  vector<Info> info;
  seg_tree(int n) : n(n), info(4 * n, Info()) {}
  void pull(int v) { info[v] = info[v * 2] + info[v * 2 + 1]; }
  void update(int v, int l, int r, int x, const Info &val) {
    if (l == r) {
      info[v] = val;
      return;
    }
    int m = (l + r) / 2;
    if (x <= m)
      update(v * 2, l, m, x, val);
    else
      update(v * 2 + 1, m + 1, r, x, val);
    pull(v);
  }
  void update(int x, const Info &val) { update(1, 0, n - 1, x, val); }
  Info query(int v, int l, int r, int x, int y) {
    if (l > y || r < x)
      return Info();
    if (l >= x && r <= y)
      return info[v];
    int m = (l + r) / 2;
    pull(v);
    return query(2 * v, l, m, x, y) + query(2 * v + 1, m + 1, r, x, y);
  }
  Info query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

struct node {
  ll suf = 0, pre = 0;
  ll tot = 0, mx = 0;
  node() = default;
  friend node operator+(node lhs, node rhs) {
    node res = {};
    res.pre = max(lhs.pre, lhs.tot + rhs.pre);
    res.suf = max(rhs.suf, lhs.suf + rhs.tot);
    res.tot = lhs.tot + rhs.tot;
    res.mx = max({lhs.mx, rhs.mx, lhs.suf + rhs.pre});
    return res;
  }
};

int main() {
  int n;
  cin >> n;
  vector<tuple<int, int, int>> A(n);
  vector<int> vals_x, vals_y;
  for (int i = 0; i < n; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    vals_x.push_back(x);
    vals_y.push_back(y);
    A[i] = {x, y, w};
  }
  sort(vals_x.begin(), vals_x.end());
  vals_x.resize(unique(begin(vals_x), end(vals_x)) - begin(vals_x));
  sort(vals_y.begin(), vals_y.end());
  vals_y.resize(unique(begin(vals_y), end(vals_y)) - begin(vals_y));
  for (int i = 0; i < n; i++) {
    auto [x, y, z] = A[i];
    x = lower_bound(begin(vals_x), end(vals_x), x) - begin(vals_x);
    y = lower_bound(begin(vals_y), end(vals_y), y) - begin(vals_y);
    A[i] = {x, y, z};
  }
  int N = vals_x.size();
  int M = vals_y.size();
  vector<vector<pair<int, node>>> updates(N);
  for (int i = 0; i < n; i++) {
    auto [x, y, w] = A[i];
    node info = {};
    info.tot = w;
    info.suf = info.pre = info.mx = max(0, w);
    updates[x].push_back({y, info});
  }
  ll mx = 0;
  for (int i = 0; i < N; i++) {
    seg_tree<node> st(M);
    for (int j = i; j < N; j++) {
      for (auto [x, nod] : updates[j]) {
        node ex = st.query(x, x);
        ex.tot += nod.tot;
        ex.suf = ex.pre = ex.mx = max(0ll, ex.tot);
        st.update(x, ex);
      }
      mx = max(mx, st.query(0, M - 1).mx);
    }
  }
  cout << mx << "\n";
}
