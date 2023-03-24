#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  int k;
  cin >> n >> k;
  vector<ll> A(k);
  for (int i=0;i<k;i++) cin >> A[i];
  ll ans = 0;
  for (int mask=1; mask < (1<<k); mask++){
    ll cnt = n;
    int bits = 0;
    for (int i=0;i<k;i++){
      if (mask & (1<<i)) {
        cnt /= A[i];
        bits++;
      }
    }
    if (bits % 2 == 0) {
      ans -= cnt;
    } else {
      ans += cnt;
    }
  }
  cout << ans << "\n";
}
