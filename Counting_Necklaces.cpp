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
  mint power(ll n) { mint res = 1; mint a = *this; while (n) { if (n % 2) res = res * a; a = a * a; n /= 2; } return res; }
  mint inv() { return power(P-2); }
  mint& operator*=(const mint& rhs) { x = norm(((ll)x * rhs.x)%P); return *this; }
  mint& operator+=(const mint& rhs) { x = norm(x + rhs.x); return *this; }
  mint& operator-=(const mint& rhs) { x = norm(x - rhs.x); return *this; }
  #define OP(OO, OOE) friend mint operator OO(mint lhs, mint rhs) { mint res = lhs; res OOE rhs; return res; }
  OP(*, *=)
  OP(+, +=)
  OP(-, -=)
};

int main() {
  int n,m;
  cin >> n >> m;
  
  vector<int> divs;
  for (int i=1;i*i<=n;i++){
    if (n % i == 0) {
      divs.push_back(i);
      if (n/i != i)
        divs.push_back(n/i);
    }
  }
  sort(begin(divs),end(divs));
  int k = divs.size();
  vector<mint> dp(k);
  dp[0] = m;
  for (int i=1;i<k;i++){
    mint sum1 = 0;
    int di = divs[i];
    for (int dj=1;dj*dj<=di;dj++){
      if (di%dj == 0) {
        int j = lower_bound(begin(divs), end(divs), dj) - divs.begin();
        sum1 += dj*dp[j];
        if (di/dj != dj && di/dj != di) {
          int j2 = lower_bound(begin(divs), end(divs), di/dj) - divs.begin();
          sum1 += (di/dj)*dp[j2];
        }
      }
    }
    dp[i] = (mint(m).power(di) - sum1)*mint(di).inv();
  }
  mint ans = 0;
  for (int i=0;i<k;i++){
    ans += dp[i];
  }
  cout << ans.val() << "\n";
  // cout << dp.back().val() << "\n";
}
