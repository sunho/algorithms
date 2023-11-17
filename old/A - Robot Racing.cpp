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
mint& operator+=(mint& a, mint b) { if ((a.x += b.x) >= MOD) a.x -= MOD; return a; }
mint& operator-=(mint& a, mint b) { if ((a.x -= b.x) < 0) a.x += MOD; return a; }
mint operator*(mint a, mint b) { return mint((ll) a.x * b.x); }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint& operator*=(mint& a, mint b) { return a = a * b; }
mint pow(mint a, ll p) { return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1); }
mint inv(mint a) { return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  int cnt = 0;
  int spaces = 0;
  mint ans = 1;
  for (int i=0;i<n;i++) {
    if (i == 0)
      spaces += A[i]-1; 
    else
      spaces += A[i]-A[i-1]-1;
    cnt++;
    if (cnt > spaces+1) {
      ans *= cnt;
      cnt--;
      spaces++;
    }
  }
  while (cnt > 1) {
    ans *= cnt;
    cnt--;
  }
  cout << ans.x << "\n";
}
