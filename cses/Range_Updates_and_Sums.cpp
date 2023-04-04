#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
  int n;
  vector<ll> t;
  vector<pair<bool,ll>> lazy;
  SegTree(int n) : n(n), t(4*n), lazy(4*n) {}

  void push(int v, int l, int r) {
    //cout << v << " " << l << " " << r << lazy[v].second << "\n";
    int tm = (l+r)/2;
    if (lazy[v].first) {
      lazy[v*2] = lazy[v*2+1] = lazy[v];
      t[v*2] = lazy[v].second * (tm-l+1);
      t[v*2+1] = lazy[v].second * (r-tm);
    } else {
      t[v*2] += lazy[v].second * (tm-l+1);
      t[v*2+1] += lazy[v].second * (r-tm);
      lazy[v*2].second += lazy[v].second;
      lazy[v*2+1].second += lazy[v].second;
    }
    lazy[v] = {false, 0};
  }

  void update_add(int l, int r, int add, int v = 1, int tl = 0, int tr = -1) {
    if (tr == -1) tr = n-1;
    if (l > r)
      return;
    if (l == tl && r == tr) {
      lazy[v].second += add;
      t[v] += (ll)add * (r-l+1);
    } else {
      push(v, tl, tr);
      int tm = (tl+tr)/2;
      update_add(l, min(r, tm), add, v*2, tl, tm);
      update_add(max(l, tm+1), r, add, v*2+1, tm+1, tr);
      t[v] = t[v*2] + t[v*2+1];
    }
  }

  void update_assign(int l, int r, int val, int v = 1, int tl = 0, int tr = -1) {
    if (tr == -1) tr = n-1;
    if (l > r)
      return;
    if (l == tl && r == tr) {
      lazy[v] = {true, val};
      t[v] = (ll)val * (r-l+1);
    } else {
      push(v, tl, tr);
      int tm = (tl+tr)/2;
      update_assign(l, min(r, tm), val, v*2, tl, tm);
      update_assign(max(l, tm+1), r, val, v*2+1, tm+1, tr);
      t[v] = t[v*2] + t[v*2+1];
    }
  }

  ll get(int l, int r, int v = 1, int tl = 0, int tr = -1) {
    if (tr == -1) tr = n-1;
    if (l > r)
      return 0;
    if (l == tl && r == tr) {
      return t[v];
    }
    push(v, tl, tr);
    t[v] = t[v*2] + t[v*2+1];
    int tm = (tl + tr) / 2;
    return get(l, min(r,tm), v*2, tl, tm) + get(max(l,tm+1),r, v*2+1, tm+1,tr);
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  SegTree st(n);
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    st.update_assign(i,i,a);
  }
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    --l,--r;
    if (t == 1) {
      int x;
      cin >> x;
      st.update_add(l,r, x);
    } else if (t == 2) {
      int x;
      cin >> x;
      st.update_assign(l,r, x);
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
