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


int main() {
  int n;
  cin >> n;
  vector<int> inv(n);
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    inv[a-1] = i;
  }
  ll ans = 0;
  fenwick_tree ft(n);
  for (int i=0;i<n;i++) {
    ans += ft.query(inv[i], n-1);
    ft.update(inv[i],1);
  }
  cout << ans << "\n";
}
