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

const int N = 5e5;
mint facts[N + 1];
mint ifacts[N + 1];
mint invs[N + 1];
mint choose(int n, int k) { return facts[n] * ifacts[n - k] * ifacts[k]; }

void solve() {
  facts[0] = 1;
  for (int i = 1; i <= N; i++) {
    facts[i] = i * facts[i - 1];
  }
  for (int i = 0; i <= N; i++) {
    ifacts[i] = inv(facts[i]);
  }
  for (int i = 1; i <= N; i++) {
    invs[i] = inv(i);
  }

  int n;
  cin >> n;
  vector<int> A(n);
  int S = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    S += A[i];
  }
  reverse(begin(A), end(A));
  int rest = S;
  int rest2 = 1;
  mint ans = 0;
  mint left = 1;
  mint right = facts[S];
  for (int i = 0; i < n; i++) {
    right *= ifacts[A[i]];
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= A[i]; j++) {
      right *= j;
      right *= invs[rest];
      rest--;
    }
    mint cc = left;
    int cur = rest2;
    for (int j = 1; j <= A[i] - 1; j++) {
      cc *= cur;
      cur++;
      cc *= invs[j];
    }
    mint s = cc * choose(S, sum + A[i]) * right;
    ans += s;
    sum += A[i];
    for (int j = 1; j <= A[i]; j++) {
      left *= rest2;
      left *= invs[j];
      rest2++;
    }
  }
  cout << ans.x << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
