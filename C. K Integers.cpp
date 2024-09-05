#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifndef ONLINE_JUDGE
#include "lib/debug.h"
#define dbg(...) std::cerr << __DEBUG_UTIL__::outer << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif


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
  vector<int> A(n);
  vector<int> inv(n);
  fenwick_tree ft(n);
  fenwick_tree ft2(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
    A[i]--;
    inv[A[i]] = i;
  }
  vector<ll> ans(n);
  ll I = 0;
  for (int i=0;i<n;i++){
    I += ft.query(inv[i],n-1);
    ft.add(inv[i], 1);
    int ng = -1, ok = n;
    while (ok - ng > 1) {
      int mid = (ok+ng)/2;
      if (ft.prefix_query(mid) >= (i+2)/2) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    ft2.add(inv[i], inv[i]);
    ll L = ft.query(0,ok), R = ft.query(ok+1,n-1);
    ans[i] = I - ft2.query(0,ok) + ok*L - L*(L-1)/2;
    ans[i] += ft2.query(ok+1,n-1) - (ok+1)*R - R*(R-1)/2;
  }
  for (int i=0;i<n;i++){
    cout << ans[i] << " ";
  }
  cout << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
