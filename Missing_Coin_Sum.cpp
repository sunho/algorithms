#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector A(n, 0);
  for (int i=0;i<n;i++) cin >> A[i];
  sort(begin(A),end(A));
  if (A[0] != 1) {
    cout << 1 << "\n";
    return;
  }
  ll cur = 1;
  for (int i=1;i<n;i++) {
    if (A[i] > cur + 1) {
      break;
    }
    cur += A[i];
  }
  cout << cur + 1 << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
