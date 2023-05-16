#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;

ll reverse(ll x) {
  while (x % 10 == 0) {
    x /= 10;
  }
  auto s = to_string(x);
  reverse(begin(s), end(s));
  return stoll(s);
}

ll f(ll x) {
  while (x % 10 == 0) {
    x /= 10;
  }
  return min(x,reverse(x));
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;

  ll x = f(k);
  ll x2 = reverse(x);
  int cnt = 0;
  while (x <= n || x2 <= n) {
    if (x <= n && f(x) == k) {
      cnt ++;
    }
    if (x2 <= n && x != x2 && f(x2) == k) {
      cnt ++;
    }
    x *= 10;
    x2 *= 10;
  }
  cout << cnt << "\n";
}
