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
  vector<int> A(n+1);
  const int N = 1e5;
  for (int i=1;i<=n;i++) {
    cin >> A[i];
  }

  vector<int> mex(n+1);
  for (int i=1;i<=n;i++){
    for (int j=i;j<=n;j+=i){
      mex[i] = max(mex[i], A[j]);
    }
  }
  
  vector<int> pf(N+2);
  for (int i=1;i<=n;i++){
    pf[mex[i]]++;
  }
  for (int i=0;i<=N;i++){
    pf[i+1] += pf[i];
  }
  
  vector<int> cnt(N+2);
  mint ans = 0;
  for (int i=n;i>=1;i--){
    ans += (mint)mex[i]*pow(mint(2),mex[i] == 0?0:pf[mex[i]-1])*pow(mint(2),cnt[mex[i]]);
    cnt[mex[i]]++;
  }
  cout << ans.x << "\n";
}
