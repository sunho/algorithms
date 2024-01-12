#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int mn = n + m - 2;
  int rem = k - mn;
  if (rem < 0) {
    cout << "NO"
         << "\n";
    return;
  }
  if (rem % 2 != 0) {
    cout << "NO"
         << "\n";
    return;
  }

  if (rem % 4 == 2) {
    if (n == 1 && m == 1) {
      cout << "NO"
           << "\n";
      return;
    }
  }
  cout << "YES"
       << "\n";
  bool flip = rem % 4 == 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (j == 0) {
        cout << "R ";
      } else {
        if (flip) {
          if (j % 2 == 0) {
            cout << "B ";
          } else {
            cout << "R ";
          }
        } else {
          if (j % 2 == 0) {
            cout << "R ";
          } else {
            cout << "B ";
          }
        }
      }
    }
    cout << "\n";
  }
  if ((m - 1) % 2 == 1) {
    flip ^= 1;
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j <= 1) {
        cout << "B ";
      } else {
        if (flip) {
          if (i % 2 == 0) {
            cout << "B ";
          } else {
            cout << "R ";
          }
        } else {
          if (i % 2 == 0) {
            cout << "R ";
          } else {
            cout << "B ";
          }
        }
      }
    }
    cout << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
