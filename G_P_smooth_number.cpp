#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void sieves(int PN, vector<ll>& lp, vector<ll>& pr) {
  lp.assign(PN+1,0);
  for (int i=2;i<=PN;i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j=0;j<pr.size()&&pr[j]<=lp[i]&&i*pr[j]<=PN;j++) {
      lp[i * pr[j]] = pr[j];
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, p;
  cin >> n >> p;
  vector<ll> lp, pr;
  sieves(p, lp, pr);
  reverse(begin(pr), end(pr));
  const int m = pr.size();
  vector<vector<ll>> powers(m);
  for (int i=0;i<m;i++){
    for (__int128_t l=1;l<=n;l*=pr[i])
      powers[i].push_back((ll)l);
  }
  vector<ll> vals;
  int start = max(m-10,0);
  auto dfs = [&](auto self, int i, ll cur) -> void {
    if (i == start) {
      vals.push_back(cur);
      return;
    }
    for (ll a : powers[i]) {
      if (cur > n/a) break;
      self(self, i+1, cur*a);
    }
  };
  dfs(dfs, 0, 1);
  sort(begin(vals), end(vals));
  vals.resize(unique(begin(vals), end(vals))-begin(vals));
  auto dfs2 = [&](auto self, int i, ll cur) -> ll {
    if (i == m) {
      return upper_bound(begin(vals), end(vals), n/cur) - begin(vals);
    }
    ll res = 0;
    for (ll a : powers[i]) {
      if (cur > n/a) break;
      res += self(self, i+1, cur*a);
    }
    return res;
  };
  ll ans = dfs2(dfs2, start, 1);
  cout << ans << "\n";
}
