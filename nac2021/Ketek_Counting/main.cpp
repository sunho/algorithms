#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;

ll binexp(ll n, int k) {
  ll res = 1;
  while (k) {
    if (k&1) res = res*n%MOD;
    n = n*n%MOD;
    k <<= 1;
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string s;
  cin >> s;
  const int n = s.size();
  int m = n/2;
  auto cal_ways = [&](char a, char b) {
    if (a == '?' && b == '?') return 26;
    if (a == '?') return 1;
    if (b == '?') return 1;
    if (a == b) return 1;
    return 0;
  };
  vector<ll> pow(n+1);
  pow[0] = 1;
  for (int i=1;i<=n;i++){
    pow[i] = pow[i-1]*26%MOD;
  }
  vector<int> pf(n+1);
  for (int i=0;i<n;i++){
    pf[i+1] = pf[i] + (int)(s[i] == '?');
  }
  vector<ll> dp(m+1);
  dp[0] = 1;
  for (int i=0;i<2*m-1;i++){
    int j = (i+1)/2;
    int l,r;
    if (i%2==0) {
      l = j, r = j;
    } else {
      l = j-1, r = j;
    }
    ll ways = 1;
    while (l >= 0 && r < m && cal_ways(s[l],s[n-r-1]) && cal_ways(s[r], s[n-l-1])) {
      ways = ways*cal_ways(s[l],s[n-r-1])%MOD;
      if (l != r) {
        ways = ways*cal_ways(s[r],s[n-l-1])%MOD;
      }
      dp[r+1] += dp[l]*ways%MOD;
      dp[r+1] %= MOD;
      l--;
      r++;
    }
  }
  ll ans = 0;
  for (int i=0;i<=m;i++){
    ans += dp[i]*(pow[pf[n-i]-pf[i]])%MOD;
    ans %= MOD;
  }
  cout << ans << "\n";
}
