#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

#define dbg(x) "(" << #x <<": " << (x) << ") "
template<typename Ostream, typename Cont>
enable_if_t<is_same_v<Ostream,ostream>, Ostream&> 
operator<<(Ostream& os, const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename ...Ts>
ostream& operator<<(ostream& os, const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}


// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 1000000007; // 998244353
struct mint {
  int v=0; 
  int val() { return v; }
  mint() = default;
  mint(ll v) : v(v % MOD) { v += (v < 0) * MOD; }
};
mint& operator+=(mint& a, mint b) { if ((a.v += b.v) >= MOD) a.v -= MOD; return a; }
mint& operator-=(mint& a, mint b) { if ((a.v -= b.v) < 0) a.v += MOD; return a; }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint operator*(mint a, mint b) { return mint((ll) a.v * b.v); }
mint& operator*=(mint& a, mint b) { return a = a * b; }
mint pow(mint a, ll p) { return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1); }
mint inv(mint a) { return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }

ostream& operator<<(ostream& os, mint p){
	return os<<p.val();
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  for (int i=0;i<n;i++)
    cin >> A[i];
  const int MK = 5050 + 1;
  int K = n*(n+1)/2;
  vector dp(n+1, array<array<mint,2>, MK>{});
  dp[0][0][0] = 1;
  int max_k = 0;
  for (int i=0;i<n;i++){
    vector next(n+1, array<array<mint,2>, MK>{});
    max_k = min(K, max_k+i+1);
    for (int last=0;last<=i;last++){
      for (int k=0;k<=max_k;k++){
        for (int z=0;z<2;z++){
          if (A[i] == 2) {
            if (k+(i-last+1) <= K) {
              next[last][k+(i-last+1)][z] += dp[last][k][z];
            }
            next[i+1][k][z^1] += dp[last][k][z];
          } else if (A[i] == 1) {
            next[i+1][k][z] += dp[last][k][z];
          } else {
            if (k+(i-last+1) <= K) {
              next[last][k+(i-last+1)][z] += dp[last][k][z];
            }
          }
        }
      }
    }
    dp = move(next);
  }

  mint ans = 0;
  for (int j=0;j<=K;j++){
    mint ddd = pow(mint(j),m);
    for (int i=0;i<=n;i++){
      mint nd = ddd * (dp[i][j][0] - dp[i][j][1]);
      ans += nd;
    }
  }
  cout << ans.v << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--)
    solve();
}
