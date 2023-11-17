#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  for (int i=0;i<n-1;i++){
    if (__builtin_popcount(i+1) != 1) {
      if (A[i] > A[i+1]) {
        cout << "NO" << "\n";
        return;
      }
    }
  }
  cout << "YES" << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
