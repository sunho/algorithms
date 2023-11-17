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

mint dp[64][8][10][10][10];

int main() {
  ll n;
  array<int,3> A{};
  cin >> n >> A[0] >> A[1] >> A[2];
  dp[0][0][0][0][0] = 1;
  for (int i=0;i<=60;i++){
    int j = 60-i;
    for (int r0=0;r0<A[0];r0++)
    for (int r1=0;r1<A[1];r1++)
    for (int r2=0;r2<A[2];r2++)
    for (int mask=0;mask<8;mask++) {
      bool over = (n & (1ll << j));
      for (int nxt=0;nxt<8;nxt++){
        int a[] = {nxt & 1, (bool)(nxt & 2), (bool)(nxt & 4)};
        int b[] = {mask & 1, mask & 2, mask & 4};
        if (a[0] ^ a[1] ^ a[2]) continue;
        bool ok = true;
        for (int z=0;z<3;z++){
          if (!over) {
            if (a[z] && !b[z])
              ok = false;
          }
        }
        if (!ok) continue;
        int nxt_mask = mask;
        ll nxt_r[] = {r0,r1,r2};
        int c = 1;
        for (int z=0;z<3;z++){
          if (over && !a[z]) {
            nxt_mask |= c;
          }
          if (a[z]) {
            nxt_r[z] += (ll)1 << j;
            nxt_r[z] %= A[z];
          }
          c <<= 1;
        }
        dp[i+1][nxt_mask][nxt_r[0]][nxt_r[1]][nxt_r[2]] += dp[i][mask][r0][r1][r2];
      }
    }
  }
  mint ans = 0;
  for (int mask=0;mask<8;mask++) {
    ans += dp[61][mask][0][0][0];
  }
  ans -= n / lcm(A[0],A[1]);
  ans -= n / lcm(A[1],A[2]);
  ans -= n / lcm(A[0],A[2]);
  ans -= 1;
  cout << ans.x << "\n";
}
