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

void sieves(int PN, vector<ll>& lp, vector<ll>& pr) {
  lp.assign(PN+1,0);
  for (int i=2;i<=PN;i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j=0;j<pr.size()&&pr[j]<=lp[i]&&i*pr[j]<=PN;j++) {
      lp[i * pr[j]] = pr[j];
    }
  }
}

int main() {
  const int N = 2e6;
  vector<ll> lp, pr;
  sieves(N, lp, pr);
  vector<mint> fact(N+1);
  fact[0] = 1;
  for (int i=1;i<=N;i++) {
    fact[i] = fact[i-1]*i;
  }

  int n;
  cin >> n;
  vector<int> A(2*n);
  vector<int> B;
  map<int,int> cnt;
  for (int i=0;i<2*n;i++){
    cin >> A[i];
    if (lp[A[i]] == A[i]) B.push_back(A[i]);
    cnt[A[i]]++;
  }
  sort(begin(B),end(B));
  B.resize(unique(begin(B),end(B))-begin(B));
  int m = B.size();
  vector<mint> dp(n+1);
  dp[0] = 1;
  for (int i=0;i<m;i++){
    vector<mint> nxt(n+1);
    for (int j=0;j<=n;j++){
      if(j != n)
        nxt[j+1] += dp[j]*cnt[B[i]];
      nxt[j] += dp[j];
    }
    dp = nxt;
  }
  mint ans = dp[n]*fact[n];
  for (auto [_, c] : cnt) {
    ans = ans / fact[c];
  }
  cout << ans.x << "\n";
}
