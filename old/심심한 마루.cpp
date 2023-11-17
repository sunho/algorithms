#include <bits/stdc++.h>

using namespace std;
using ll = long long;
struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n+1) {}
  void add(int idx, int val) {
    for (++idx; idx <= n; idx += idx & -idx)
        bits[idx] += val;
  }

  void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
  }

  int point_query(int idx) {
      int ret = 0;
      for (++idx; idx > 0; idx -= idx & -idx)
          ret += bits[idx];
      return ret;
  }
};


int main() {
  int n;
  cin >> n;
  int m = 360;
  fenwick_tree ft(m);
  for (int i=0;i<n;i++) {
    int a, b;
    cin >> a >> b;
    int l = a-b, r=a+b;
    if (2*b+1 >= 360) {
      ft.range_add(0,m-1,1);
      continue;
    }
    if (l < 0) {
      ft.range_add(l+m, m-1, 1);
      l = 0;
    } 
    if (r >= m) {
      ft.range_add(0, r-m, 1);
      r = m-1;
    }
    assert(l <= r);
    ft.range_add(l,r,1);
  }
  int ans = 0;
  for (int i=0;i<m;i++){
    if (ft.point_query(i)) {
      ans++;
    }
  }
  cout << ans << "\n";
}
