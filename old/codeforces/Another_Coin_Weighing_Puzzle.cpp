#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void sieves(int PN, vector<ll>& lp, vector<ll>& pr, vector<ll>& mobius) {
  lp.assign(PN+1,0);
  mobius.assign(PN+1,0);
  mobius[1] = 1;
  for (int i=2;i<=PN;i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      mobius[i] = -1;
      pr.push_back(i);
    }
    for (int j=0;j<pr.size()&&i*pr[j]<=PN;j++) {
      lp[i * pr[j]] = pr[j];
      if (i % pr[j] == 0) {
        continue;
      } else {
        mobius[i * pr[j]] = mobius[i] * mobius[pr[j]];
      }
    }
  }
}

const int MOD = 998244353;

int binexp(ll n, int k) {
  ll res = 1;
  while (k) {
    if (k & 1) res = n * res % MOD;
    n = n * n % MOD;
    k/=2;
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  vector<ll> lp, pr, mobius;
  sieves(k, lp, pr, mobius);
  ll ans = 1;
  for (int i=1;i<=k;i++){
    ans += mobius[i] * (binexp(k/i*2+1, n)-1);
    ans %= MOD;
  }
  ans += MOD;
  ans %= MOD;
  cout << ans << "\n";
}
