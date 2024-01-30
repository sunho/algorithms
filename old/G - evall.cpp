#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 998244353;
template<class T> T power(T a, ll b) { T res = 1; for (; b; b /= 2, a *= a) { if (b % 2) { res *= a; } } return res; }
struct mint {
  int x;
  static int norm(int x) { if (x < 0) { x += MOD; } if (x >= MOD) { x -= MOD; } return x; }
  int val() const { return x; }
  mint(int x = 0) : x(norm(x)) {}
  mint(ll x) : x(norm((int)(x % MOD))) {}
  mint operator-() const { return mint(norm(MOD - x)); }
  mint inv() const { assert(x != 0); return power(*this, MOD - 2); }
  mint& operator*=(const mint& rhs) { x = (int)(ll(x) * rhs.x % MOD); return *this; }
  mint& operator+=(const mint& rhs) { x = norm(x + rhs.x); return *this; }
  mint& operator-=(const mint& rhs) { x = norm(x - rhs.x); return *this; }
  mint& operator/=(const mint& rhs) { return *this *= rhs.inv();}
  friend mint operator*(const mint& lhs, const mint& rhs) { mint res = lhs; res *= rhs; return res; }
  friend mint operator+(const mint& lhs, const mint& rhs) { mint res = lhs; res += rhs; return res; }
  friend mint operator-(const mint& lhs, const mint& rhs) { mint res = lhs; res -= rhs; return res; }
  friend mint operator/(const mint& lhs, const mint& rhs) { mint res = lhs; res /= rhs; return res; }
  friend ostream& operator << (ostream& out, const mint& rhs) { out << rhs.val(); return out; }
  friend istream& operator >> (istream& in, mint& rhs) { ll x; in >> x; rhs = mint(x); return in; }
};
mint inv(mint a) { return power(a, MOD - 2); }

void solve() {
  string s;
  cin >> s;
  const int n = s.size();
  int cur_cnt = 0;
  int cnt = 0;
  mint cur = 0;
  mint prev = 1;
  bool first = false;
  mint ans = 0;
  for (int i=0;i<n;i++){
    if (s[i] == '+') {
      cnt += cur_cnt;
      cur_cnt = 0;
      ans -= cur;
      cur = 0;
      prev = 1;
      first = false;
    } else if (s[i] == '*') {
      prev = cur;
      first = false;
    } else {
      if (!first) {
        cur = prev * (s[i]-'0');
        first = true;
      } else {
        cur *= 10;
        cur += prev * (s[i]-'0');
      }
      cur_cnt++;
      ans += cur;
      ans += cur * cnt;
    }
  }
  cur = 0;
  prev = 1;
  mint ten = 1;
  cnt = 0;
  cur_cnt = 0;
  for (int i=n-1;i>=0;i--){
    if (s[i] == '+') {
      cnt += cur_cnt;
      ans -= cur;
      cur_cnt = 0;
      cur = 0;
      prev = 1;
      ten = 1;
    } else if (s[i] == '*') {
      prev = cur;
      ten = 1;
    } else {
      cur += ten * prev * (s[i]-'0');
      ten *= 10;
      cur_cnt++;
      ans += cur;
      ans += cur * cnt;
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
