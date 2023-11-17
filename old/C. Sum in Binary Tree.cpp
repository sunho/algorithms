#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int t;
  cin >> t;
  while (t--){
    ll x;
    cin >> x;
    ll ans = 1;
    while (x != 1) {
      ans += x;
      x/=2;
    }
    cout << ans << "\n";
  }
}
