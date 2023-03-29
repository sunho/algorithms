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
int MOD = 1000000007; // 998244353
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
  int n,m;
  cin >> n >> m;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  mint zeros = 0;
  for (int l=0;l<n;l++){
    for (int r=l;r<n;r++){
      if (A[r] == 1) break;
      zeros+=1;
    }
  }
  int last = 0;
  int first = 0;
  for (int i=n-1;i>=0;i--){
    if (A[i] != 1) 
      break;
    last++;
  }
  for (int i=0;i<n;i++){
    if (A[i] != 1) 
      break;
    first++;
  }
  A = vector<int>(A.begin() + first, A.end() - last);
  n = A.size();
  vector<mint> dp(n+1);
  vector<mint> facts(n+1);
  facts[0] = 1;
  for(int i=1;i<=n;i++){
    facts[i] = (m-i+1)*facts[i-1];
  }
  dp[0] = 1;
  mint ans = 0;
  int l_last = 0;
  for (int i=0;i<n;i++){
    if (A[i] == 2)
      l_last = i;
  }
  for (int k=1;k<=n;k++){
    vector<mint> next(n+1);
    for (int l=0;l<n;l++){
      bool found = false;
      for (int r=l+1;r<=n;r++){
        if (A[r-1] == 2) {
          found = true;
        }
        if (A[r-1] == 1) {
          if (found) {
            int z = r;
            while (z <= n && A[z-1] == 1) {
              z++;
            }
            while (z <= n) {
              next[z] += dp[l];
              if (A[z-1] == 2)
                break;
              z++;
            }
          }
          break;
        } 
        if (found || r >= l_last) {
          next[r] += dp[l];
        }
      }
    }
    ans += next[n] * (pow(zeros, m) - pow(zeros-k, m));
    dp = move(next);
    cout << dbg(dp) dbg(ans) dbg(zeros) << "\n";
  }
  cout << ans.val() << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--)
    solve();
}
