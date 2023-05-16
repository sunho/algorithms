#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  int x;
  cin >> x;
  vector<int> W(n);
  for (int i=0;i<n;i++){
    cin >> W[i];
  }
  vector<ll> pf(2*n+1);
  for (int i=0;i<2*n;i++){
    pf[i+1] = pf[i] + W[i%n];
  }
  auto step = [&](int start) -> pair<int,ll> {
    ll cnt = 0;
    int rem = x;
    rem %= pf[n];
    cnt += (ll)n * (x / pf[n]);
    int nxt = lower_bound(begin(pf)+start, end(pf), pf[start] + rem) - begin(pf);
    cnt += nxt - start;
    nxt %= n;
    return {nxt, cnt};
  };
  vector<int> vis(n);
  vector<int> prd(n);
  vector<ll> cnts;
  vector<int> path;
  int len = 0;
  int cur = 0;
  while (true) {
    vis[cur] = true;
    len++;
    auto [nxt, cnt] = step(cur);
    cnts.push_back(cnt);
    if (vis[nxt]) {
      int p = cur;
      while (p != nxt) {
        path.push_back(p);
        p = prd[p];
      }
      path.push_back(nxt);
      break;
    }
    prd[nxt] = cur;
    cur = nxt;
  }
  int pre_len = len - path.size();
  while(q--) {
    ll k;
    cin >> k;
    --k;
    if (k < pre_len) {
      cout << cnts[k] << "\n";
    } else {
      cout << cnts[pre_len + (k -  pre_len) % path.size()] << "\n";
    }
  }
}
