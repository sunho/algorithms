#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  for (int l=0;l<=n;l++){
    int t = 0;
    for (int i=0;i<n;i++){
      if (l < A[i]) t++;
    }
    if (l == t) {
      cout << l << "\n";
      return;
    }
  }
  cout << -1 << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
