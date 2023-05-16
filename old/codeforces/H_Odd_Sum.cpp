#include <bits/stdc++.h>
using namespace std;
using ll = long long;
  
const int MOD = 998244353;
struct mint {
  int x;
  mint(int x = 0) : x(x) { }
  mint operator+(mint o) const { return x + o.x < MOD ? x + o.x : x + o.x - MOD; }
  mint operator-(mint o) const { return x - o.x < 0 ? x - o.x + MOD : x - o.x; }
  mint operator*(mint o) const { return int(ll(x) * o.x % MOD); }
  mint &operator+=(mint o) { return *this = *this + o; }
  mint &operator-=(mint o) { return *this = *this - o; }
  mint &operator*=(mint o) { return *this = *this * o; }
  mint inv() const { return pow(MOD - 2); }
  mint pow(ll x) const {
    mint a = *this;
    mint b = 1;
    for (; x; x >>= 1) {
      if (x & 1)
        b *= a;
      a *= a;
    }
    return b;
  }
};
  
const int NN = 1 << 21;
mint w[NN];
void init_w() {
  w[NN / 2] = 1;
  const mint g = mint(3).pow(MOD / NN);
  for (int i = NN / 2 + 1; i < NN; ++i) w[i] = w[i - 1] * g;
  for (int i = NN / 2 - 1; i > 0; --i) w[i] = w[i << 1];
}

void fft(vector<mint>& a, bool inv) {
  const int m = a.size();
  for (int i=1,j=0;i<m;i++){
    int bit = m >> 1;
    for (; j & bit; bit >>= 1)
      j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int l=1;l<m;l*=2) {
    for (int i=0;i<m;i+=2*l){
      for (int j=0;j<l;j++){
        mint even = a[i+j], odd = a[i+j+l];
        mint y = w[l+j]*odd;
        a[i+j] = even + y;
        a[i+j+l] = even - y;
      }
    }
  }
  if (inv) {
    mint minv = mint(m).inv();
    reverse(a.begin()+1,a.end());
    for (mint& v : a) v = v*minv;
  }
}
  
int ilog2(int n) {
  int res = 0;
  while (n >>= 1) res++;
  return res;
}
  
vector<mint> convolution(const vector<mint>& a, const vector<mint>& b) {
  int m = 2<<ilog2(a.size()+b.size()-1);
  vector<mint> a2(m), b2(m);
  copy(a.begin(), a.end(), a2.begin());
  copy(b.begin(), b.end(), b2.begin());
  fft(a2,false), fft(b2,false);
  for (int i=0;i<m;i++) a2[i] *= b2[i];
  fft(a2,true);
  return a2;
}
  
const int N = 1e5;
  
mint facts[N+1];
mint ifacts[N+1];
  
mint choose(int n, int k) {
  return facts[n]*ifacts[k]*ifacts[n-k];
}
  
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  
  init_w();
  
  int n,m;
  cin >> n >> m;
  
  facts[0] = 1;
  for (int i=1;i<=n;i++){
    facts[i] = facts[i-1] * i;
  }
  for (int i=0;i<=n;i++){
    ifacts[i] = facts[i].inv();
  }
  
  vector<int> cnt(11);
  
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    cnt[a]++;
  }
  
  vector<vector<mint>> dp(2, vector<mint>(m+1));
  dp[0][0] = 1;
  for (int a=1;a<=10;a++){
    auto next = dp;
    int c = cnt[a];
    if (c == 0) continue;
    vector<mint> odd(c*a+1), even(c*a+1);
    for (int i=1;i<=c;i++){
      if (i % 2 == 0) {
        even[i*a] = choose(c, i);
      } else {
        odd[i*a] = choose(c, i);
      }
    }
    for (int z=0;z<2;z++) {
      auto dp_x = convolution(dp[z^1], odd);
      auto dp_y = convolution(dp[z], even);
      for (int i=0;i<=m;i++){
        next[z][i] += dp_x[i] + dp_y[i];
      }
    }
    dp = move(next);
  }
  cout << dp[1][m].x << "\n";
}