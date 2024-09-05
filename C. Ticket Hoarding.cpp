#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;

template<typename T=ll>
struct fenwick_tree {
  int n;
  vector<T> bits;
  fenwick_tree(int n) : n(n), bits(n + 1) {}
  void set(int v, T delta) {
    add(v, -get(v,v));
    add(v, delta);
  }
  void add(int v, T delta) {
    for (++v; v <= n; v += v & (-v))
      bits[v] += delta;
  }
  T get(int i) { return query(i,i); }
  T query(int l, int r) { return prefix_query(r) - prefix_query(l - 1); }
  T prefix_query(int r) {
    T res = 0;
    for (++r; r > 0; r -= r & (-r))
      res += bits[r];
    return res;
  }
};


void solve() {
  int n;
  cin >> n;
  int m, k;
  cin >> m >> k;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  pqg<pair<int,int>> pq;
  for (int i=0;i<n;i++){
    pq.push({A[i], -i});
  }
  ll ans = 0;
  vector<int> c(n);
  while (!pq.empty() && k) {
    auto [a, i] = pq.top();
    pq.pop();
    i *= -1;
    int z = min(k, m);
    ans += (ll)a*z;
    c[i] += z;
    k-=z;
  }
  ll cnt = 0;
  for (int i=0;i<n;i++){
    ans += cnt * c[i];
    cnt += c[i];
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
