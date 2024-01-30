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
  int n;
  cin >> n;
  string s,t;
  cin >> s >> t;
  vector<set<int>> idx(26);
  for (int i=0;i<n;i++){
    idx[s[i]-'A'].insert(i);
  }
  fenwick_tree ft(n);
  ll ans = 0;
  for (int i=0;i<n;i++){
    auto& left = idx[t[i]-'A'];
    int ll = *left.begin();
    ans += ll - ft.query(0,ll);
    ft.update(ll, 1);
    left.erase(left.begin());
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
