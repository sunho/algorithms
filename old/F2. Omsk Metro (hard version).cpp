#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e18;

struct info {
  info(ll a) {
    pref_mx = max(0ll, a);
    suf_mx = max(0ll, a);
    pref_mn = min(0ll, a);
    suf_mn = min(0ll, a);
    sum = a;
    mx = max(a,0ll);
    mn = min(a,0ll);
  }
  info() = default;
  ll pref_mx = 0;
  ll suf_mx = 0;
  ll pref_mn = 0;
  ll suf_mn = 0;
  ll sum = 0;
  ll mx = 0;
  ll mn = 0;
};

info merge(info l, info r) {
  info res;
  res.pref_mx = max(l.pref_mx, l.sum + r.pref_mx);
  res.pref_mn = min(l.pref_mn, l.sum + r.pref_mn);
  res.suf_mx = max(r.suf_mx, l.suf_mx + r.sum);
  res.suf_mn = min(r.suf_mn, l.suf_mn + r.sum);
  res.sum = l.sum + r.sum;
  res.mx = max({l.mx,r.mx,l.suf_mx+r.pref_mx});
  res.mn = min({l.mn,r.mn,l.suf_mn+r.pref_mn});
  return res;
}

const int lg = 20;

void solve() {
  int n;
  cin >> n;
  vector<vector<info>> infoes(n+2, vector<info>(lg));
  vector<vector<int>> up(n+2, vector<int>(lg));
  vector<int> depth(n+2);

  infoes[1][0] = info(1);
  depth[1] = 1;
  for (int l=1;l<lg;l++) {
    up[1][l] = up[up[1][l-1]][l-1];
    infoes[1][l] = merge(infoes[1][l-1], infoes[up[1][l-1]][l-1]);
  }
  int id = 2;
  for (int i=0;i<n;i++){
    char a;
    cin >> a;
    if (a == '+') {
      int u = id++;
      int v,x;
      cin >> v >> x;
      up[u][0] = v;
      infoes[u][0] = info(x);
      depth[u] = depth[v] + 1;
      for (int l=1;l<lg;l++) {
        up[u][l] = up[up[u][l-1]][l-1];
        infoes[u][l] = merge(infoes[u][l-1], infoes[up[u][l-1]][l-1]);
      }
    } else {
      int u,v,k;
      cin >> u >> v >> k;
      if (depth[u] < depth[v]) swap(u,v);
      int diff = depth[u] - depth[v];
      info a,b;
      for (int i=lg-1;i>=0;i--){
        if ((diff >> i) & 1) {
          a = merge(a, infoes[u][i]);
          u = up[u][i];
        }
      }
      if (u == v) {
        a = merge(a, infoes[u][0]);
      } else {
        for (int i = lg-1; i>=0;i--) {
          if (up[u][i] != up[v][i]) {
            a = merge(a, infoes[u][i]);
            u = up[u][i];
            b = merge(b, infoes[v][i]);
            v = up[v][i];
          }
        }
        a = merge(a, infoes[u][1]);
        b = merge(b, infoes[v][0]);
      }
      swap(b.pref_mn, b.suf_mn);
      swap(b.pref_mx, b.suf_mx);
      auto merged = merge(a,b);
      if (merged.mn <= k && k <= merged.mx) {
        cout << "YES" << "\n";
      } else {
        cout << "NO" << "\n";
      }
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();  
  }
}
