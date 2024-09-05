#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
    --A[i];
  }
  for (int i=0;i<n;i++){
    if (A[A[i]] == i) {
      cout << 2 << "\n";
      return;
    }
  }
  cout << 3 << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
