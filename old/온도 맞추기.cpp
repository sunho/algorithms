#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> X(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    A[i] = b - A[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> X[i];
  }
  vector<int> so_lame(n);
  iota(begin(so_lame), end(so_lame), 0);
  if (any_of(so_lame.begin(), so_lame.end(),
             [&](int i) { return A[i] % X[i] != 0; })) {
    cout << -1 << "\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    A[i] /= X[i];
  }
  int mod = (A[0] % 2 + 2) % 2;
  if (any_of(so_lame.begin(), so_lame.end(),
             [&](int i) { return (A[i] % 2 + 2) % 2 != mod; })) {
    cout << -1 << "\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    A[i] = abs(A[i]);
  }
  cout << *max_element(begin(A), end(A)) << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
