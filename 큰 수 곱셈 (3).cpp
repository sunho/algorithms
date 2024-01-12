#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 998244353;
struct mint {
  int x;
  mint() : x(0) {}
  mint(ll val) : x(val % MOD) { x += (x < 0) * MOD; }
};
mint &operator+=(mint &a, mint b) {
  if ((a.x += b.x) >= MOD)
    a.x -= MOD;
  return a;
}
mint &operator-=(mint &a, mint b) {
  if ((a.x -= b.x) < 0)
    a.x += MOD;
  return a;
}
mint operator*(mint a, mint b) { return mint((ll)a.x * b.x); }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }
mint pow(mint a, ll p) {
  return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mint inv(mint a) { return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }

int ilog2(int n) {
  int res = 0;
  while (n >>= 1)
    res++;
  return res;
}

const int WN = 1 << 21;
mint w[WN];
void init_w() {
  w[WN / 2] = 1;
  mint g = pow(mint(3), MOD / WN);
  for (int i = WN / 2 + 1; i < WN; ++i)
    w[i] = w[i - 1] * g;
  for (int i = WN / 2 - 1; i > 0; --i)
    w[i] = w[i << 1];
}

void ntt(vector<mint> &a) {
  int m = a.size();
  for (int l = m / 2; l; l /= 2) {
    for (int i = 0; i < m; i += l * 2) {
      for (int j = 0; j < l; j++) {
        mint x = a[i + j], y = a[i + j + l];
        a[i + j + l] = (x - y) * w[j + l];
        a[i + j] = x + y;
      }
    }
  }
}

void intt(vector<mint> &a) {
  int m = a.size();
  for (int l = 1; l < m; l *= 2) {
    for (int i = 0; i < m; i += l * 2) {
      for (int j = 0; j < l; j++) {
        mint x = a[i + j];
        mint y = w[j + l] * a[i + j + l];
        a[i + j] = x + y, a[i + j + l] = x - y;
      }
    }
  }

  mint iv = inv(mint(m));
  for (mint &v : a)
    v *= iv;
  reverse(a.begin() + 1, a.end());
}

vector<mint> poly_mul(const vector<mint> &a, const vector<mint> &b) {
  const int n = a.size() + b.size() - 1;
  const int m = 2 << ilog2(n);
  vector<mint> a2(m), b2(m);
  copy(a.begin(), a.end(), a2.begin());
  copy(b.begin(), b.end(), b2.begin());
  ntt(a2), ntt(b2);
  for (int i = 0; i < m; i++)
    a2[i] *= b2[i];
  intt(a2);
  a2.resize(n);
  return a2;
}

void solve() {
  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();
  vector<mint> A(n), B(m);
  for (int i = 0; i < n; i++) {
    A[i] = a[i] - '0';
  }
  for (int i = 0; i < m; i++) {
    B[i] = b[i] - '0';
  }
  reverse(begin(A), end(A));
  reverse(begin(B), end(B));
  auto C = poly_mul(A, B);
  string s;
  ll x = 0;
  for (int i = 0; i < n + m - 1; i++) {
    x += C[i].x;
    s.push_back('0' + (x % 10));
    x /= 10;
  }
  while (x) {
    s.push_back('0' + (x % 10));
    x /= 10;
  }
  reverse(begin(s), end(s));
  cout << s << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  init_w();
  solve();
}
