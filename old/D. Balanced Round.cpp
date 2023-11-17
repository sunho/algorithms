#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  sort(begin(A), end(A));
  int last = A[0];
  int ans = 1e9;
  int deleted = 0;
  for (int i=0;i<n;i++){
    if (A[i]-last > k) {
      ans = min(ans,deleted + n-i);
      deleted = i;
    }
    last = A[i];
  }
  cout << min(ans,deleted) << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
