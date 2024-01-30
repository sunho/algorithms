#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 1000000007; // 998244353
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

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<ll, ll>> A(n), B(m), C(k);
  for (int i = 0; i < n; i++) {
    cin >> A[i].first >> A[i].second;
  }
  for (int i = 0; i < m; i++) {
    cin >> B[i].first >> B[i].second;
  }
  for (int i = 0; i < k; i++) {
    cin >> C[i].first >> C[i].second;
  }
  mint ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (mint)2 * A[i].first * A[i].first * m * k;
    ans += (mint)2 * A[i].second * A[i].second * m * k;
  }
  for (int i = 0; i < m; i++) {
    ans += (mint)2 * B[i].first * B[i].first * n * k;
    ans += (mint)2 * B[i].second * B[i].second * n * k;
  }
  for (int i = 0; i < k; i++) {
    ans += (mint)2 * C[i].first * C[i].first * m * n;
    ans += (mint)2 * C[i].second * C[i].second * m * n;
  }
  auto work = [&](auto &A, auto &B, auto &C) {
    mint L = 0, R = 0;
    for (int i = 0; i < A.size(); i++) {
      L += A[i].first;
    }
    for (int i = 0; i < A.size(); i++) {
      R += A[i].second;
    }
    mint res = 0;
    for (int i = 0; i < B.size(); i++) {
      res += B[i].second * L * C.size();
      res -= B[i].first * L * C.size();
      res -= B[i].second * R * C.size();
    }
    for (int i = 0; i < C.size(); i++) {
      res -= C[i].second * L * B.size();
      res -= C[i].first * L * B.size();
      res -= C[i].second * R * B.size();
    }
    return res;
  };
  ans += work(A, B, C);
  ans += work(B, C, A);
  ans += work(C, A, B);
  cout << ans.x << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
