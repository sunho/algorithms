#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n + 1) {}
  void update(int v, int delta) {
    for (++v; v <= n; v += v & (-v))
      bits[v] += delta;
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r & (-r))
      res += bits[r];
    return res;
  }
  ll query(int l, int r) { return query(r) - query(l - 1); }
};

void solve() {
  int n, m;
  cin >> n >> m;
  fenwick_tree ft(n);
  set<int> S;
  for (int i = 0; i < n; i++) {
    S.insert(i);
  }
  int rem = 0;
  int ans = 0;
  for (int i = 0; i < m; i++) {
    rem++;
    int l, r;
    cin >> l >> r;
    if (l == r) {
      continue;
    }
    int cnt = ft.query(l, r - 1);
    int need = r - l - cnt;
    if (need != 0) {
      for (auto it = S.lower_bound(l); it != S.upper_bound(r - 1);) {
        ft.update(*it, 1);
        it = S.erase(it);
      }
    }
    int k = min(rem, need);
    rem -= k;
    need -= k;
    ans += need;
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
