#include <bits/stdc++.h>

using ll = long long;

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int m,k;
    ll a1,ak;
    cin >> m >> k >> a1 >> ak;
    int x = m / k;
    int r = m % k;
    int R = max(a1 - r, 0ll);
    cout << max(0ll, x - ak - R/k) + max(0ll, r - a1) << "\n";
  }
  
}
