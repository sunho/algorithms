#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007; // 998244353
struct mint {
  int x;
  mint(int x = 0) : x(norm(x)) { }
  mint(ll x) : x(norm(x%MOD)) { }
  int norm(int x) const { if (x < 0) { x += MOD; } if (x >= MOD) { x -= MOD; } return x; }
  mint operator+(mint o) const { return norm(x + o.x); }
  mint operator-(mint o) const { return norm(x - o.x); }
  mint operator*(mint o) const { return ll(x) * o.x; }
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

const int N = (int)2e5;
mint facts[N+1];
mint ifacts[N+1];

mint choice(int n, int k) {
  return facts[n]*ifacts[n-k];
}

void solve() {
  int n;
  cin >> n;

  vector<int> A(n), B(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  for (int i=0;i<n;i++) {
    cin >> B[i];
  }
  sort(A.begin(), A.end());
  map<int, int> cnt;
  for (int i=0;i<n;i++) {
    cnt[B[i]]++;
  }
  bool ok = true;
  mint ans = 1;
  int m = 0;
  for (auto it=cnt.rbegin();it!=cnt.rend();it++){
    auto [a, c] = *it;
    int k = upper_bound(A.begin(), A.end(), a) - A.begin();
    int nn = n - k;
    if (nn - m < c) {
      ok = false;
      break; 
    }
    ans *= choice(nn-m, c);
    m += c;
  }
  if (ok) {
    cout << ans.x << "\n";
  } else {
    cout << 0 << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  facts[0] = 1;
  for (int i=1;i<=N;i++) {
    facts[i] = facts[i-1]*i;
  }
  for (int i=0;i<=N;i++){
    ifacts[i] = facts[i].inv();
  }


  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
