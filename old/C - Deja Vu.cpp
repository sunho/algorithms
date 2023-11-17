#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  set<int> vis;
  while(q--) {
    int x;
    cin >> x;
    if (vis.count(x)) continue;
    vis.insert(x);
    int xx = 1 << x;
    for (int i=0;i<n;i++) {
      if (A[i] % xx == 0) {
        A[i] += xx / 2;
      }
    }
  }
  for (int i=0;i<n;i++) {
    cout << A[i] << " ";
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
