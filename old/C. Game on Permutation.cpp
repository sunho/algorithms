#include <bits/stdc++.h>

using ll = long long;
using namespace std;

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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0;i<n;i++) cin >> A[i];
    vector<int> id(n);
    iota(begin(id),end(id),0);
    sort(begin(id),end(id), [&](int i, int j){
      return A[i] < A[j];
    });
    fenwick_tree ft(n);
    fenwick_tree ft2(n);
    int ans = 0;
    for (int i : id) {
      if (ft2.query(i) && !ft.query(i)) {
        ans ++;
        ft.update(i, 1);
      }
      ft2.update(i, 1);
    }
    cout << ans << "\n";
  }
}
