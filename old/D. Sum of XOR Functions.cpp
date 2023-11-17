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
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  mint ans = 0;
  for (int k=0;k<30;k++){
    vector<int> C(n);
    for (int i=0;i<n;i++){
      C[i] = (A[i] >> k) & 1;
    }
    vector<vector<ll>> pf(2, vector<ll>(n+1));
    vector<vector<ll>> cnt(2, vector<ll>(n+1));
    for (int i=n-1;i>=0;i--){
      for (int d : {0, 1}) {
        pf[d][i] = pf[d^C[i]][i+1] + (C[i]==d)*(i+1);
        cnt[d][i] = cnt[d^C[i]][i+1] + (C[i]==d);
      }
    }
    ll basis = 1 << k;
    for (int l=0;l<n;l++) {
      ans += basis * (pf[1][l] - (mint)cnt[1][l]*l);
    }
  }
  cout << ans.x << "\n";
}
