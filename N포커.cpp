#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 10007; // 998244353
struct mint {
  int x;
  mint() : x(0) {}
  mint(ll val) : x(val % MOD) { x += (x < 0) * MOD; }
};
mint& operator+=(mint& a, mint b) { if ((a.x += b.x) >= MOD) a.x -= MOD; return a; }
mint operator*(mint a, mint b) { return mint((ll) a.x * b.x); }
mint pow(mint a, ll p) { return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1); }
mint inv(mint a) { return pow(a, MOD - 2); }

const int N = 52;
mint facts[N+1];

mint choose(int n, int r) {
  return facts[n]*inv(facts[r])*inv(facts[n-r]);
}

mint f(int n, int k) {
  if (n-4*k < 0)
    return 0;
  else
    return choose(N-4*k,n-4*k);
}

int main() {
  facts[0] = 1;
  for (int i=1;i<=N;i++){
    facts[i] = i * facts[i-1];
  }

  int n;
  cin >> n;

  mint ans = 0;
  for (int i=1;i<=13;i++){
    ans += ((i&1) ? 1 : -1)*choose(13,i)*f(n,i);
  }
  cout << ans.x;
}
