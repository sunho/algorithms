#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Modular Integer
// does arithematics (mod P) automatically
int P = 1000000007; // 998244353
struct mint {
  int x;
  int norm(int x) const { if (x < 0) { x += P; } if (x >= P) { x -= P; } return x; }
  mint(int x = 0) : x(norm(x)) {}
  mint(ll x) : x(norm(x % P)) {}
  int val() const { return x; }
  mint power(int n) { mint res = 1; mint a = *this; while (n) { if (n % 2) res = res * a; a = a * a; n /= 2; } return res; }
  mint inv() { return power(P-2); }
  mint& operator*=(const mint& rhs) { x = norm(((ll)x * rhs.x)%P); return *this; }
  mint& operator+=(const mint& rhs) { x = norm(x + rhs.x); return *this; }
  mint& operator-=(const mint& rhs) { x = norm(x - rhs.x); return *this; }
  #define OP(OO, OOE) friend mint operator OO(mint lhs, mint rhs) { mint res = lhs; res OOE rhs; return res; }
  OP(*, *=)
  OP(+, +=)
  OP(-, -=)
};

void solve() {
  int n,m;
  cin >> n >> m;
  const int N = 1<<n;
  vector<mint> dp(N);
  dp[0] = 1;
  vector trans(N, vector<int>());
  for (int mask1=0;mask1<N;mask1++){
    for (int mask2=0;mask2<N;mask2++){
      bool ok = true;
      int empty = 0;
      for (int j=0;j<n;j++){
        if ((mask2 & (1<<j))) {
          if ((mask1 & (1<<j))) 
            ok = false;
          if (empty % 2 != 0)
            ok = false;
          empty = 0;
        } else {
          if (!(mask1 & (1<<j)))
            empty++;
          else {
            if (empty % 2 != 0)
              ok = false;
            empty = 0;
          }
        }
      }
      if (empty % 2 != 0)
        ok = false;
      if (ok) {
        trans[mask1].push_back(mask2);
      }
    }
  }
  for (int i=0;i<m-1;i++){    
    vector<mint> next(N);
    for (int mask=0;mask<N;mask++){
      for (int mask2 : trans[mask]) {
        next[mask2] += dp[mask];
      }
    }
    dp = move(next);
  }
  mint ans = 0;
  for (int mask=0;mask<N;mask++){
    int empty = 0;
    bool ok = true;
    for (int j=0;j<n;j++){
      if ((mask & (1<<j))) {
        if (empty % 2 != 0) {
          ok = false;
        }
        empty = 0;
      } else {
        empty++;
      }
    }
    if (empty % 2 != 0) {
      ok = false;
    }
    if (ok) ans += dp[mask];
  }
  cout << ans.val() << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
