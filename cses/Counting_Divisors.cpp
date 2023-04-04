#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N = 1e6+10;

void solve() {
  int n;
  cin >> n;
  int m = n;
  ll ans = 1;
  bool is_prime = true;
  for (int i=2;i*i<=n;i++){
    int cnt = 1;
    while (m%i == 0) {
      is_prime = false;
      m/=i;
      cnt ++;
    }
    ans *= cnt;
  }
  if (m!=1) ans *= 2;
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
