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
  vector<int> B(n);
  for (int i=0;i<n;i++){
    cin >> B[i];
  }
  if (A == B) {
    cout << "POSSIBLE" << "\n";
    return;
  }
  for (int i=0;i<n-2;i++){
    if (B[i] < B[i+1] && B[i+1] < B[i+2]) {
      cout << "POSSIBLE" << "\n";
      return;
    }
    if (B[i] > B[i+1] && B[i+1] > B[i+2]) {
      cout << "POSSIBLE" << "\n";
      return;
    }
  }
  cout << "IMPOSSIBLE" << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
