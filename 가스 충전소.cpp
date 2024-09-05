#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, X, F;
  cin >> n >> X >> F;
  vector<tuple<int,int,int>> A(n);
  for (int i=0;i<n;i++){
    int x,p,a;
    cin >> x >> p >> a;
    A[i] = {x,p,a};
  }
  A.push_back({X,0,0});
  map<int, int> fuel;
  auto subtract = [&](int k, int v) {
    fuel[k] -= v;
    if (fuel[k] == 0) {
      fuel.erase(k);
    }
  };
  ll ans = 0;
  int tot = 0;
  for (int i=0;i<=n;i++){
    if (i != 0) {
      int dist = get<0>(A[i])-get<0>(A[i-1]);
      if (tot < dist) {
        cout << -1 << "\n";
        return;
      }
      while (dist) {
        int k = min(fuel.begin()->second, dist);
        ans += (ll)k*fuel.begin()->first;
        tot -= k;
        dist -= k;
        subtract(fuel.begin()->first, k);
      }
    }
    if (i == n) break;
    auto [_,c,w] = A[i];
    int add = min(F-tot,w);
    int kk = w - add;
    while (!fuel.empty() && kk > 0 && (--fuel.end())->first > c) {
      int cc = (--fuel.end())->first;
      int k = min(fuel[cc], kk);
      add += k;
      kk -= k;
      tot -= k;
      subtract(cc, k);
    }
    if (add != 0) {
      fuel[c] += add;
      tot += add;
    }
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
