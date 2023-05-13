#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    ll x,y,z;
    cin >> x >> y >> z;
    ll cnt = 0;
    ll k = min(y/2, z);
    cnt += k;
    y -= k*2, z -= k;
    k = min(z/2, x);
    cnt += k;
    z -= k*2, x-= k;
    k = min(y/2, x/2);
    cnt += k;
    y -= k*2, x-= k*2;
    k = min(z, x/3);
    cnt += k;
    z -= k, x -= 3*k;
    k = x/5;
    cnt += k;
    cout << cnt << "\n";
  }
}
