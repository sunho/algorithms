#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, q;
  cin >> n;
  ll sum = 0;
  vector<int> A(n);
  vector<bool> B(n, 1);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    sum += A[i];
  }
  cout << sum << "\n";
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int i, x;
      cin >> i >> x;
      --i;
      if (B[i]) {
        sum -= A[i];
      }
      A[i] = x;
      if (B[i]) {
        sum += A[i];
      }
    } else {
      int i;
      cin >> i;
      --i;
      if (B[i]) {
        sum -= A[i];
        B[i] = 0;
      } else {
        sum += A[i];
        B[i] = 1;
      }
    }
    cout << sum << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
