#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++)
    cin >> A[i];
  const int N = (int)2e5+1;
  using BS = bitset<N>;
  BS dp{};
  dp[0] = true;
  for (int i=0;i<n;i++){
    dp |= (dp >> i << (A[i] + i));
  }
  ll ans = 0;
  ll sum = 0;
  for (int i=0;i<=2*n;i++){
    if (i < n) {
      sum += A[i];
    }
    if (dp[i]) {
      ans = max(ans, sum-i);
    }
  }
  cout << ans << "\n";
}
