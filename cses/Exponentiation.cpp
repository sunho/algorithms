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
  zint power(int n) { zint res = 1; zint a = *this; while (n) { if (n % 2) res = res * a; a = a * a; n /= 2; } return res; }
  zint inv() { return power(P-2); }
  #define OP(OO, OOE) zint& operator OOE(const zint& rhs) { x = norm((ll(x) OO rhs.x) % P); return *this; }\
  friend zint operator OO(zint lhs, zint rhs) { zint res = lhs; res OOE rhs; return res; }
  OP(*, *=)
  OP(+, +=)
  OP(-, -=)
};

void solve() {
  int a,b;
  cin >> a >> b;
  cout << zint(a).power(b).val() << "\n";
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
