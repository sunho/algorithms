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
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  map<int,int> inv;
  for (int i=0;i<n;i++){
    inv[A[i]] = i;
  }
  sort(A.begin(), A.end());
  ll res = 0;
  fenwick_tree ft(n);
  for (int i=0;i<n;i++){
    ft.update(i,1);
  }
  for (int i=0;i<n;i++){
    int j = inv[A[i]];
    ft.update(j,-1);
    res += min(ft.query(0,j), ft.query(j, n-1));
  }
  cout << res << "\n";
}
