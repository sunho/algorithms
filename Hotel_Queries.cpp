#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int inf = 1e9;

// Segment Tree for min query
struct SegTree {
  int n;
  vector<int> t;
  SegTree(int n) : n(n), t(4*n, -inf) {}

  // build segment tree from static data
  void build(const vector<int>& A, int v=1, int tl=0, int tr=-1) {
    if (tr == -1) tr = n-1;
    if (tl == tr) {
      t[v] = A[tl];
    } else {
      int tm = (tl + tr) / 2;
      build(A, 2*v,tl,tm);
      build(A, 2*v+1,tm+1,tr);
      t[v] = max(t[v*2], t[v*2+1]);
    }
  }

  // query the combinded value on [l,r]
  int query(int a, int v=1, int tl=0, int tr=-1) {
    if (tr == -1) tr = n-1;
    if (tl == tr) {
      if (t[v] >= a) {
        return tl;
      } else {
        return tl+1;
      }
    }
    int tm = (tl + tr) / 2;
    if (t[v*2] >= a) {
      return query(a, v*2, tl, tm);
    } else {
      return query(a, v*2+1, tm+1, tr);
    }
  }

  // update the node at pos
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
    t[v] = max(t[v*2], t[v*2+1]);
  }
};

void solve() {
  int n,q;
  cin >> n >> q;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  SegTree st(n);
  st.build(A);
  while (q--){
    int a;
    cin >> a;
    int i = st.query(a);
    if (i == n) {
      cout << 0 << " ";
    } else {
      cout << i + 1 << " ";
      A[i]-=a;
      st.update(i, A[i]);
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
