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
  if (n == 1) {
    cout << 1 << "\n";
    return;
  }
  int ans = 1;
  int k = 0;
  for (int i=0;i<n-1;i++){
    if (A[i+1]-A[i] < 0) {
      if (k != -1) {
        ans++;
        k = -1;
      }
    }
    if (A[i+1]-A[i] > 0) {
      if (k != 1) {
        ans++;
        k = 1;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
