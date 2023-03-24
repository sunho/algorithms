#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> d(n), a(n);
  for (int i=0;i<n;i++){
    cin >> a[i] >> d[i];
  }
  sort(begin(a),end(a));
  ll ans = 0;
  ll t = 0;
  for (int i=0;i<n;i++){
    ans += d[i];
    t += a[i];
    ans -= t;
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
