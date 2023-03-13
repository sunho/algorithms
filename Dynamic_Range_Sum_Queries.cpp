#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct FenwickTree {
  int n;
  vector<ll> bits;
  FenwickTree(int n) : n(n), bits(n+1) {}
  void update(int v, int delta) {
    for (++v; v <= n; v += v&(-v)) 
      bits[v] += delta;
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r&(-r)) {
      res += bits[r];
    }
    return res;
  }
  ll query(int l, int r) {
    return query(r) - query(l-1);
  }
};

void solve() {
  int n,q;
  cin >> n >> q;
  FenwickTree ft(n);
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
    ft.update(i, A[i]);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int v,a;
      cin >> v >> a;
      --v;
      ft.update(v, a-A[v]);
      A[v] = a; 
    } else {
      int l,r;
      cin >> l >> r;
      --l,--r;
      cout << ft.query(l,r) << "\n";
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
