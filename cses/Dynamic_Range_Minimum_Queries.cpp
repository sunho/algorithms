#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int inf = 1e9;

// min query
struct SegTree {
  int n;
  vector<int> t;
  SegTree(int n) : n(n), t(4*n, inf) {}
  void build(const vector<int>& A, int v=1, int tl=0, int tr=-1) {
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

  int query(int l, int r, int v=1, int tl=0, int tr=-1) {
    if (tr == -1) tr = n-1;
    if (l > r) return inf;
    if (l == tl && r == tr) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    int x = query(l, min(r,tm), v*2, tl, tm);
    int y = query(max(tm+1,l), r, v*2+1, tm+1, tr);
    return min(x,y);
  }

  void update(int pos, int val, int v=1, int tl=0, int tr=-1) {
    if (tr == -1) tr = n-1;
    if (tl == tr) {
      t[v] = val;
      return;
    } 
    int tm = (tl + tr)/2;
    if (pos <= tm) {
      update(pos, val, v*2, tl, tm);
    } else {
      update(pos, val, v*2+1, tm+1,tr);
    }
    t[v] = min(t[v*2], t[v*2+1]);
  }
};


void solve() {
  int n,q;
  cin >> n >> q;
  SegTree st(n);
  vector A(n, 0);
  for (int i=0;i<n;i++) cin >> A[i];
  st.build(A);
  while(q--){
    int t,a,b;
    cin >> t >> a >> b;
    if (t == 1) {
      --a;
      st.update(a, b);
    } else {
      --a,--b;
      cout << st.query(a, b) << "\n";
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
