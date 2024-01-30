#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  int ans = 0;
  auto go = [&](int k) {
    int g = 0;
    for (int i=0;i<k;i++){
      int diff = 0;
      for (int j=0;j<n/k-1;j++){
        diff = gcd(abs(A[i+(j+1)*k]-A[i+j*k]),diff);
      }
      g = gcd(g,diff);
    }
    if (g > 1 || g == 0) {
      ans++;
    }
  };
  for (int k=1;k*k<=n;k++){
    if (n%k == 0) {
      if (n/k == k) {
        go(k);
      } else {
        go(n/k);
        go(k);
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
