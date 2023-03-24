#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  int l=0, r=0;
  int ans = 0;
  ll sum = 0;
  while (l < n) {
    while (r < n && sum < x) {
      sum += A[r];
      r++;
    }
    if (sum == x) {
      ans ++;
    }
    sum -= A[l];
    l++;
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
