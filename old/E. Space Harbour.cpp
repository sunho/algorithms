#include <bits/stdc++.h>

using namespace std;
using ll = __int128_t;

struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n + 1) {}
  void update(int v, ll delta) {
    for (++v; v <= n; v += v & (-v))
      bits[v] += delta;
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r & (-r))
      res += bits[r];
    return res;
  }
  ll query(int l, int r) { return query(r) - query(l - 1); }
};

void print(__int128 x) {
  if (x < 0) {
    cout << '-';
    x = -x;
  }
  if (x > 9)
    print(x / 10);
  cout << (int)(x % 10);
}


void solve() {
  int n,m,q;
  cin >> n >> m >> q;
  vector<int> X(m);
  set<int> S;
  S.insert(-1);
  S.insert(n);
  for (int i=0;i<m;i++){
    cin >> X[i];
    X[i]--;
    S.insert(X[i]);
  }
  vector<ll> V(n);
  fenwick_tree ft(n);
  for (int i=0;i<m;i++){
    int v;
    cin >> v;
    V[X[i]] = v;
  }
  auto get_v = [&](int i) -> ll {
    if (i < 0 || i >= n) return 0ll;
    return V[i];
  };
  auto sum = [&](ll x) {
    return x*(x+1)/2;
  };
  for (auto it = S.begin(); it != S.end(); it++){
    if (*it < 0 || *it >= n) continue;
    auto jt = next(it);
    ft.update(*it, get_v(*it)*sum(*jt-*it-1));
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, v;
      cin >> x >> v;
      --x;
      auto prv = --S.upper_bound(x);
      auto nxt= S.upper_bound(x);
      ft.update(*prv, -ft.query(*prv,*prv));
      ft.update(*prv, get_v(*prv)*sum(x-*prv-1));
      ft.update(x, -ft.query(x,x));
      ft.update(x, v*sum(*nxt-x-1));
      V[x] = v;
      S.insert(x);
    } else {
      int l,r;
      cin >> l >> r;
      --l,--r;
      ll ans = 0;
      auto u1 = S.lower_bound(l);
      auto u2 = --S.lower_bound(r);
      if (u2 != S.begin() && *u1 <= *prev(u2)) {
        ans += ft.query(*u1,*prev(u2));
      }
      auto sln = S.lower_bound(l);
      auto sll = prev(sln);
      auto srn = S.lower_bound(r);
      auto srr = prev(srn);
      if (*sln == *srn) {
        ans += get_v(*sll)*(sum(*sln-l)-sum(*srn-r-1));
      } else {
        ans += get_v(*sll)*(sum(*sln-l)) + get_v(*srr)*(sum(*srn-*srr-1)-sum(*srn-r-1));
      }
      print(ans);
      cout << "\n";
    }
  }
  
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
