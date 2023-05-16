#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 998244353; // 998244353
struct mint {
  int v;
  mint() : v(0) {}
  mint(ll v) : v(v % MOD) { v += (v < 0) * MOD; }
};
mint& operator+=(mint& a, mint b) { if ((a.v += b.v) >= MOD) a.v -= MOD; return a; }
mint& operator-=(mint& a, mint b) { if ((a.v -= b.v) < 0) a.v += MOD; return a; }
mint operator*(mint a, mint b) { return mint((ll) a.v * b.v); }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint& operator*=(mint& a, mint b) { return a = a * b; }
mint pow(mint a, ll p) { return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1); }
mint inv(mint a) { return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int q;
  cin >> q;
  deque<int> num;
  num.push_back(1);
  mint c = 1;
  mint ten = 1;
  while (q--){
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      ten *= 10;
      c *= 10;
      c += x;
      num.push_back(x);
    } else if (t == 2) {
      c -= num.front() * ten;
      ten = ten / 10;
      num.pop_front();
    } else {
      cout << c.v << "\n";
    }
  }
}
