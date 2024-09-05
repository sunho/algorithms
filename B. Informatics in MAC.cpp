#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifndef ONLINE_JUDGE
#include "lib/debug.h"
#else
#define dbg(x...) 
#endif


void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<int> pf(n+1), sf(n+1);
  set<int> S;
  int cur = 0;
  for (int i=0;i<n;i++){
    S.insert(A[i]);
    while (S.count(cur)) {
      cur++;
    }
    pf[i+1] = cur;
  }
  S.clear();
  cur = 0;
  for (int i=n-1;i>=0;i--){
    S.insert(A[i]);
    while (S.count(cur)) {
      cur++;
    }
    sf[i] = cur;
  }
  for (int i=1;i<=n-1;i++){
    if (pf[i] == sf[i]) {
      cout << 2 << "\n";
      cout << 1 << " " << i << "\n";
      cout << i + 1 << " " << n << "\n";
      return;
    }
  }
  cout << -1 << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
