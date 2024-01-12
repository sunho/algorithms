#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Segment Tree
const int inf = 1e9;
template <typename Info> struct seg_tree {
  int n;
  vector<Info> info;
  seg_tree(int n) : n(n), info(4 * n, Info()) {
    auto build = [&](auto &&self, int v, int l, int r) {
      if (l == r) {
        return;
      } else {
        int m = (l + r) / 2;
        self(self, v * 2, l, m);
        self(self, v * 2 + 1, m + 1, r);
        info[v] = info[v * 2] + info[v * 2 + 1];
      }
    };
    build(build, 1, 0, n - 1);
  }
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
  int val = 0;
  int val2 = 1;
  node() = default;
  friend node operator+(node lhs, node rhs) {
    return {lhs.val || rhs.val, lhs.val2 && rhs.val2};
  }
};

void solve() {
  int n, k;
  cin >> n >> k;
  vector<seg_tree<node>> dp(3, seg_tree<node>(n + 1));
  for (int i = 1; i <= n; i++) {
    {
      int mn = max(0, i - k / 2);
      if (mn == 0) {
        dp[0].update(i, {1, 1});
        dp[1].update(i, {1, 1});
      } else {
        int x = dp[1].query(mn, i - 1).val;
        dp[0].update(i, {x, x});
        x = dp[2].query(mn, i - 1).val2;
        dp[1].update(i, {!x, !x});
      }
    }
    {
      int mn = max(0, i - k);
      if (mn == 0) {
        dp[2].update(i, {1, 1});
      } else {
        int x = dp[0].query(mn, i - 1).val2;
        dp[2].update(i, {!x, !x});
      }
    }
  }
  int ok = dp[0].query(n, n).val;
  if (ok) {
    cout << "A and B win"
         << "\n";
  } else {
    cout << "C win"
         << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
