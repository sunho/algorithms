#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  set<ll> S;
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    S.insert(a);
  }
  const ll inf = 2e9;
  ll ans = inf;
  while (*S.begin() <= inf) {
    auto it = S.begin();
    ll a = *it;
    ans = min(ans,*--S.end() - a);
    S.insert(2 * a);
    S.erase(it);
  }
  ans = min(ans, *--S.end() - *S.begin());
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
