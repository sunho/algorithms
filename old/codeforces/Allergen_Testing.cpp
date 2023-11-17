#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    ll n,d;
    cin >> n >> d;
    if (n == 1) {
      cout << 0 << "\n";
      continue;
    }
    __int128_t tmp = 1;
    int cnt = 0;
    while (tmp < n) {
      tmp *= (d+1);
      cnt++;
    }
    cout << cnt << "\n";
  }
}
