#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll ans = 1;
  int n;
  cin >> n;
  for (int i=0;i<n;i++){
    ll a;
    cin >> a;
    ans *= a;
  }
  ans += n-1;
  ans *= 2022;
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
