#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 998244353;

void solve() {
  int l,r;
  cin >> l >> r;
  int cnt = 0;
  int tt = l;
  while (2*tt <= r) {
    tt *= 2;
    cnt++;
  }
  int p = (1<<(cnt-1))*3;
  int q = 1<<cnt;
  ll up = ((ll)r - (ll)p * l)/p;
  up %= MOD;
  ll up2 = ((ll)r - (ll)q * l)/q;
  up2 %= MOD;
  ll ans = 0;
  if (cnt != 0 && (ll)p*l <= r) {
    ans += (ll)(up+1)*(cnt);
    ans %= MOD;
  }
  ans += (ll)(up2+1);
  ans %= MOD;
  cout << cnt+1 << " " << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
