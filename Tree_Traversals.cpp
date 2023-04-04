#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1e9;

// Segment Tree for min query
struct seg_tree {
  int n;
  vector<pair<int,int>> t;
  seg_tree(int n) : n(n), t(4*n, {inf,inf}) {}

  // build segment tree from static data
  void build(const vector<pair<int,int>>& A, int v=1, int tl=0, int tr=-1) {
    if (tr == -1) tr = n-1;
    if (tl == tr) {
      t[v] = A[tl];
    } else {
      int tm = (tl + tr) / 2;
      build(A, 2*v,tl,tm);
      build(A, 2*v+1,tm+1,tr);
      t[v] = min(t[v*2], t[v*2+1]);
    }
  }

  // query the combinded value on [l,r]
  pair<int,int> query(int l, int r, int v=1, int tl=0, int tr=-1) {
    if (tr == -1) tr = n-1;
    if (l > r) return {inf,inf};
    if (l == tl && r == tr) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    auto x = query(l, min(r,tm), v*2, tl, tm);
    auto y = query(max(tm+1,l), r, v*2+1, tm+1, tr);
    return min(x,y);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> pre(n), ino(n);
  seg_tree st(n);
  for (int i=0;i<n;i++) {
    cin >> pre[i];
    pre[i]--;
  }
  for (int i=0;i<n;i++) {
    cin >> ino[i];
    ino[i]--;
  }
  vector<int> inv(n), inv2(n);
  for (int i=0;i<n;i++){
    inv[ino[i]] = i;
    inv2[pre[i]] = i;
  }
  vector<pair<int,int>> vals(n);
  for (int i=0;i<n;i++){
    vals[i] = {inv2[ino[i]], ino[i]};
  }
  st.build(vals);

  auto f = [&](auto self, int l, int r) -> void {
    if (l > r)
      return;
    if (l == r) {
      cout << ino[l] + 1 << " ";
      return;
    }
    auto [_, root] = st.query(l, r);
    
    int u = inv[root];
    self(self, l, u-1);
    self(self, u+1, r);
    cout << ino[u] + 1 << " ";
  };
  f(f, 0, n-1);
}
