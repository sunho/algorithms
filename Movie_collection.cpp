#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n+1) {}
  void update(int v, int delta) { 
    for (++v; v <= n; v += v&(-v)) bits[v] += delta;
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r&(-r)) res += bits[r];
    return res;
  }
  ll query(int l, int r) { return query(r) - query(l-1); }
};

void solve() {
  int n,m;
  cin >> n >> m;
  const int N = n+m;
  fenwick_tree ft(N);
  vector<int> pos(n);
  for (int i=0;i<n;i++){
    ft.update(i, 1);
    pos[n-i-1] = i;
  }
  int tp = n;
  for (int i=0;i<m;i++){
    int x;
    cin >> x;
    --x;
    cout << ft.query(pos[x]+1, N-1) << " ";
    ft.update(pos[x], -1);
    pos[x] = tp;
    ft.update(tp, 1);
    tp++;
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
