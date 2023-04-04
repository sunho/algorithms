#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  for (int i=0;i<n;i++){
    cin >> A[i] >> B[i];
  }
  int ans = 1;
  ll c = B[0];
  ll gg = A[0];
  int cur = 1;
  while (cur < n) {
    ll nc = lcm((ll)B[cur], c);
    int nnd = nc / c;
    c = nc;
    ll d = c/B[cur];
    if (A[cur] % d != 0 || gg % nnd != 0) {
      c = B[cur];
      gg = A[cur];
      ans ++;
    } else {
      gg = gcd(A[cur]/d, gg/nnd);
    }
    cur++;
  }
  cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
