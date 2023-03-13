#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
  int n;
  vector<ll> t;
  vector<pair<ll,int>> lazy;
  SegTree(int n) : n(n), t(4*n), lazy(4*n) {}

  void build(const vector<int>& A, int v=1, int tl=0, int tr=-1) {
    if (tr == -1) tr = n-1;
    if (tl == tr) {
      t[v] = A[tl];
    } else {
      int tm = (tl+tr)/2;
      build(A, v*2, tl, tm);
      build(A, v*2+1, tm+1, tr);
      t[v] = (ll)t[v*2] + t[v*2+1];
    }
  }

  void push(int v, int l, int r) {
    int tm = (l+r)/2;
    ll T1 = (ll)lazy[v].first + (ll)lazy[v].second*(tm-l);
    ll T2 = (ll)lazy[v].first + (ll)lazy[v].second*(r-l);
    ll L = (T1 + lazy[v].first) * (tm-l+1) / 2;
    ll R = (T2 + lazy[v].first) * (r-l+1) / 2;
    t[v*2] += L;
    t[v*2+1] += R-L;
    lazy[v*2].first += lazy[v].first;
    lazy[v*2].second += lazy[v].second;
    lazy[v*2+1].first += lazy[v].first + lazy[v].second*(tm-l+1);
    lazy[v*2+1].second += lazy[v].second;
    lazy[v] = {0,0};
  }
  
  void update(int l, int r, ll start, int v = 1, int tl = 0, int tr = -1) {
    if (tr == -1) tr = n-1;
    if (l > r) return;
    if (l == tl && r == tr) {
      ll R = (ll)(r-start+2)*(r-start+1)/2;
      ll L = (ll)(l-start+1)*(l-start)/2;
      t[v] += R - L;
      lazy[v].first += l-start+1;
      lazy[v].second += 1;
    } else {
      int tm = (tl+tr)/2;
      push(v, tl, tr);
      update(l, min(tm,r), start, v*2, tl, tm);
      update(max(l,tm+1), r, start, v*2+1, tm+1, tr);
      t[v] = t[v*2] + t[v*2+1];
    }
  }

  ll get(int l, int r, int v = 1, int tl = 0, int tr = -1) {
    if (tr == -1) tr = n-1;
    if (l > r) return 0;
    if (l == tl && r == tr) {
      return t[v];
    }
    push(v, tl, tr);
    int tm = (tl+tr)/2;
    return get(l, min(tm,r), v*2, tl, tm) + get(max(l,tm+1), r, v*2+1, tm+1, tr);
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  SegTree st(n);
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  st.build(A);
  while(q--) {
    int t,l,r;
    cin >> t >> l >> r;
    --l,--r;
    if (t==1) {
     st.update(l,r,l);
    } else {
     cout << st.get(l,r) << "\n";
    }
  }
}

int main() {
  cin.sync_with_stdio(false);

  solve();

  return 0;
}
