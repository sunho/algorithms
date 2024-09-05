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
  int cnt = 0;
  for (int i=0;i<n;i++){
    for (int j=0;j<i;j++){
      if (A[j] > A[i]) {
        cnt++;
      }
    }
  }
  if (cnt % 2 == 0) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
