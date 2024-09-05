#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifndef ONLINE_JUDGE
#include "lib/debug.h"
#else
#define dbg(x...) 
#endif


const ll inf = 1e18;
template<class T, T def, auto combine>
struct seg_tree {
  int n;
  vector<T> bits;
  seg_tree(int n) : n(n), bits((n+1)*2, def) {}
  void set(int k, T x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2) bits[k] = combine(bits[k*2], bits[k*2+1]);
  }
  T get(int i) {
    return bits[i+n];
  }
  T query(int l, int r) {
    T res = def;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1) res = combine(res, bits[l++]);
      if (!(r & 1)) res = combine(res, bits[r--]);
    }
    return res;
  }
};

struct node {
  int w = 0;
  array<int, 30> y{};
  node() = default;
  node(int w, array<int,30> y) : w(w), y(y) {}
};

node combine(node a, node b) { 
  node res{};
  res.w = a.w | b.w;
  for (int i=0;i<30;i++){
    res.y[i] = a.y[i] + b.y[i];
  }
  return res;
}
using node_seg_tree = seg_tree<node,node{},combine>;

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }
  int q;
  cin >> q;
  node_seg_tree st(n);
  for (int i=0;i<n;i++){
    auto [x, y] = A[i];
    array<int,30> yy{};
    if (x == y) {
      st.set(i, {x, yy});
      continue;
    }
    int w = 0;
    for (int j=29;j>=0;j--){
      if ((x >> j & 1) == (y >> j & 1)) {
        w |= (x & (1 << j));
      } else {
        break;
      }
    }
    y -= w;
    for (int j=29;j>=0;j--) {
      if (y >> j & 1) {
        yy[j] = 1;
      }
    }
    st.set(i, {w,yy});
  }
  while (q--){
    int l,r;
    cin >> l >> r;
    --l,--r;
    auto node = st.query(l,r);
    dbg(l, r, node.y)
    int res = 0;
    for (int i=29;i>=0;i--){
      if (node.y[i] == 1) {
        res |= (1 << i);
        if (node.w >> i & 1) {
          if (i != 0) {
            res |= ((1<<i) - 1);
          }
        }
      } else if (node.y[i] > 1) {
        res |= (1 << i);
        if (i != 0) {
          res |= ((1<<i) - 1);
        }
      }
    }
    res |= node.w;
    cout << res << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
