#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int P = 1000000007; // 1000000007
struct zint {
  int x;
  int norm(int x) const { if (x < 0) { x += P; } if (x >= P) { x -= P; } return x; }
  zint(int x = 0) : x(norm(x)) {}
  zint(ll x) : x(norm(x % P)) {}
  int val() const { return x; }
  #define OP(OO, OOE) zint& operator OOE(const zint& rhs) { x = norm((ll(x) OO rhs.x) % P); return *this; }\
  friend zint operator OO(zint lhs, zint rhs) { zint res = lhs; res OOE rhs; return res; }
  OP(*, *=)
  OP(+, +=)
  OP(-, -=)
};

zint power(zint a, int x) {
  zint res = 1;
  while (x) {
    if (x % 2)
      res = res * a;
    a = a * a;
    x /= 2;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  cout << power(zint(2), n).val();
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
