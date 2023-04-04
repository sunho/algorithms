#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  const ll inf = 1e18;
  ll ans = inf;
  for (ll a = 1; a <= (m+a-1)/a; a++){
    ll b = (m+a-1)/a;
    if (a <= n && b <= n) {
      ans = min(ans, a*b);
    }
  }
  if (ans == inf){
    cout << -1;
  } else {
    cout << ans;
  }
}
