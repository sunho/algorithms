#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int a = n; a >= 1; a--) {
    int i = find(begin(A), end(A), a) - begin(A);
    if (i == n - 1 || i == 0)
      continue;
    for (int j = i; j <= n - 2; j++) {
      if (A[j - 1] < A[j] && A[j] > A[j + 1]) {
        swap(A[j], A[j + 1]);
      } else {
        break;
      }
    }
  }
  if (is_sorted(begin(A), end(A))) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
