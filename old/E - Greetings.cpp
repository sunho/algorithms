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
  vector<pair<int,int>> A(n);
  vector<int> vals;
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
    vals.push_back(A[i].first);
    vals.push_back(A[i].second);
  }
  sort(begin(vals),end(vals));
  vals.resize(unique(begin(vals),end(vals))-begin(vals));
  for (int i=0;i<n;i++){
    A[i].first = lower_bound(begin(vals),end(vals),A[i].first) - begin(vals);
    A[i].second = lower_bound(begin(vals),end(vals),A[i].second) - begin(vals);
  }
  sort(rbegin(A),rend(A),[](auto x, auto y) {
    return x.second < y.second;
  });
  const int m = vals.size();
  fenwick_tree ft(m);
  ll ans = 0;
  for (int i=0;i<n;i++){
    auto [l,r] = A[i];
    ans += ft.query(0,l);
    ft.update(l,1);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
