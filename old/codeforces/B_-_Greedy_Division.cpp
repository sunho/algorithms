#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

// mod int
// inv() and division doesn't work if P is not prime
template<class T> T power(T a, ll b) { T res = 1; for (; b; b /= 2, a *= a) { if (b % 2) { res *= a; } } return res; }
int P = 998244353; // 1000000007
struct zint {
  int x;
  // assumes -P <= x <= 2P
  int norm(int x) const { if (x < 0) { x += P; } if (x >= P) { x -= P; } return x; }
  zint(int x = 0) : x(norm(x)) {}
  zint(ll x) : x(norm((int)(x % P))) {}
  int val() const { return x; }
  zint operator-() const { return zint(norm(P - x)); }
  zint inv() const { assert(x != 0); return power(*this, P - 2); }
  zint& operator*=(const zint& rhs) { x = (int)(ll(x) * rhs.x % P); return *this; }
  zint& operator+=(const zint& rhs) { x = norm(x + rhs.x); return *this; }
  zint& operator-=(const zint& rhs) { x = norm(x - rhs.x); return *this; }
  zint& operator/=(const zint& rhs) { return *this *= rhs.inv();}
  friend zint operator*(const zint& lhs, const zint& rhs) { zint res = lhs; res *= rhs; return res; }
  friend zint operator+(const zint& lhs, const zint& rhs) { zint res = lhs; res += rhs; return res; }
  friend zint operator-(const zint& lhs, const zint& rhs) { zint res = lhs; res -= rhs; return res; }
  friend zint operator/(const zint& lhs, const zint& rhs) { zint res = lhs; res /= rhs; return res; }
  friend ostream& operator << (ostream& out, const zint& rhs) { out << rhs.val(); return out; }
  friend istream& operator >> (istream& in, zint& rhs) { ll x; in >> x; rhs = zint(x); return in; }
};

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i=0;i<n;i++) cin >> A[i];
  const int N = 100*100;
  vector<vector<zint>> dp(n+1, vector<zint>(N+1));
  dp[0][0] = 1;
  int sum = 0;
  for (int i=0;i<n;i++)
    sum += A[i];
  if (sum%2!=0) {
    cout << 0 << "\n";
    return;
  }
  for(int i=0;i<n;i++){
    vector<vector<zint>> next(n+1, vector<zint>(N+1));
    for(int j=0;j<=n;j++){
      for(int z=0;z<=N;z++){
        next[j][z] += dp[j][z];
        if (z + A[i] <= N && j + 1 <= n) {
          next[j+1][z+A[i]] += dp[j][z];
        }
      }
    }
    dp = move(next);
  }
  vector<zint> fact(n+1);
  fact[0] = 1;
  for(int i=1;i<=n;i++){
    fact[i] = fact[i-1]*i;
  }
  zint ans = 0;
  for (int i=1;i<n;i++){
    ans += dp[i][sum/2] * fact[i] * fact[n-i];
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
