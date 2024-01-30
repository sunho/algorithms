#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<ll> pf(n+1);
  for (int i=0;i<n;i++){
    if (i%2 == 0) {
      pf[i+1] = pf[i] + A[i];
    } else {
      pf[i+1] = pf[i] - A[i];
    }
  }
  bool yes = false;
  set<ll> S;
  for (int i=0;i<=n;i++){
    if (S.count(pf[i])) {
      yes = true;
      break;
    }
    S.insert(pf[i]);
  }
  if (yes) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
