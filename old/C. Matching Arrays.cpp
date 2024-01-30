#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> A(n), B(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }
  vector<int> id(n);
  iota(begin(id), end(id), 0);
  sort(begin(id), end(id), [&](int i, int j) { return A[i] < A[j]; });
  sort(rbegin(B), rend(B));
  sort(begin(B) + (n - x), end(B));
  sort(begin(B), begin(B) + (n - x));
  int score = 0;
  vector<int> inv(n);
  for (int i = 0; i < n; i++) {
    if (A[id[i]] > B[i]) {
      score++;
    }
    inv[id[i]] = i;
  }
  if (score != x) {
    cout << "NO"
         << "\n";
    return;
  }
  cout << "YES"
       << "\n";
  for (int i = 0; i < n; i++) {
    cout << B[inv[i]] << " ";
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
