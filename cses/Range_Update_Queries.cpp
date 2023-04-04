#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct FenwickTree {
  int n;
  vector<ll> bits;
  FenwickTree(int n) : n(n), bits(n+1) {}
  void update(int v, int delta) {
    for (++v; v > 0; v -= v&(-v)) 
      bits[v] += delta;
  }
  void update(int l, int r, int delta) {
    update(r, delta);
    update(l-1, -delta);
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r <= n; r += r&(-r))
      res += bits[r];
    return res;
  }
};

void solve() {
  int n,q;
  cin >> n >> q;
  FenwickTree ft(n);
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    ft.update(i,i,a);
  }
  while(q--){
    int t;
    cin >> t;
    if (t == 2) {
      int i;
      cin >> i;
      --i;
      cout << ft.query(i) << "\n";
    } else {
      int l,r,d;
      cin >> l >> r >> d;
      --l,--r;
      ft.update(l,r,d);
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
