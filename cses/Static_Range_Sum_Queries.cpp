#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,q;
  cin >> n >> q;
  vector pf(n+1, 0ll);
  vector A(n, 0);
  for (int i=0;i<n;i++) cin >> A[i];
  for (int i=0;i<n;i++) pf[i+1] = pf[i] + A[i];
  while (q--) {
    int l,r;
    cin >> l >> r;
    --l,--r;
    cout << pf[r+1] - pf[l] << "\n";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
