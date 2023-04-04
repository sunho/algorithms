#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >>n;
  vector<int> A(n);

  for (int i=0;i<n;i++){
    cin >> A[i];
  }

  for (int x=0;x<(1<<8);x++){
    int cur = 0;
    for (int i=0;i<n;i++) {
      cur ^= A[i];
      cur ^= x;
    }
    if (cur == 0) {
      cout << x << "\n";
      return;
    } 
  }
  cout << -1 << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;

  while(t--) {
    solve();
  }
}
