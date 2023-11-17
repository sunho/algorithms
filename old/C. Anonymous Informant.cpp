#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  set<int> vis;
  int d = 0;
  bool ok = true;
  while (!vis.count(d)) {
    vis.insert(d);
    if (A[(n-1-d+n)%n] > n) {
      ok = false;
      break;
    }
    k--;
    d += A[(n-1-d+n)%n];
    d %= n;
  }
  if (ok || k <= 0) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
