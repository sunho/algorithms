#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  const ll inf = 1e18;
  int n;
  cin >> n;
  int s;
  cin >> s;
  s--;
  vector<int> A(n-1);
  for (int i=0;i<n-1;i++) {
    cin >> A[i];
  }
  vector<ll> pf(n);
  for (int i=0;i<n-1;i++){
    pf[i+1] = pf[i] + A[i];
  }
  auto sum = [&](int l, int r) -> ll {
    return pf[r+1] - pf[l];
  };
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
  auto f = [&](auto&& self, int l, int r, int st) -> ll {
    auto& sdp = dp[l][r][st];
    if (sdp != -1) {
      return sdp;
    }
    if (l == 0 && r == n-1) {
      return 0;
    }
    ll ret = inf;
    if (l != 0) {
      ret = min(ret, self(self, l-1,r,0) + (st == 1 ? sum(l-1,r-1)*(n-(r-l+1)) : sum(l-1,l-1)*(n-(r-l+1))));
    }
    if (r != n-1) {
      ret = min(ret, self(self, l,r+1,1) + (st == 1 ? sum(r,r)*(n-(r-l+1)) : sum(l,r)*(n-(r-l+1))));
    }
    return sdp = ret;
  };
  cout << f(f,s,s,0) << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
