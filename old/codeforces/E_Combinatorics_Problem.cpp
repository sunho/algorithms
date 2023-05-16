#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  const int MOD = 998244353;

  int n, a1, x, y, m, k;
  cin >> n >> a1 >> x >> y >> m >> k;
  vector<ll> A(n);
  A[0] = a1;
  for (int i=1;i<n;i++){
    A[i] = (x*A[i-1] + y) % m;
  }
  vector<ll> B(n+1);
  vector<ll> series(k);
  for (int i=0;i<n;i++){
    for (int j=k-1;j>=1;j--){
      series[j] += series[j-1]; 
      series[j] %= MOD;
    }
    series[0] += A[i];
    series[0] %= MOD;
    B[i+1] = (B[i] + series[k-1]) % MOD;
  }
  for (int i=1;i<=n;i++){
    B[i] *= i;
  }
  ll ans = 0;
  for (int i=1;i<=n;i++){
    ans ^= B[i];
  }
  cout << ans << "\n";
}
