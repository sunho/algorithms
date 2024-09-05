#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifndef ONLINE_JUDGE
#include "lib/debug.h"
#else
#define dbg(x...) 
#endif


void solve() {
  int n,x;
  cin >> n >> x;
  --x,--n;
  int p = n-x;
  set<int> divs;
  for (int i=1;i*i<=p;i++){
    if (p % i == 0) {
      divs.insert(i);
      divs.insert(p/i);
    }
  }
  p = n + x;
  for (int i=1;i*i<=p;i++){
    if (p % i == 0) {
      divs.insert(i);
      divs.insert(p/i);
    }
  }
  int ans = 0;
  for (ll d : divs) {
    if (d % 2 == 0) {
      if (n % d < d/2) {
        if (n%d == x) {
          ans++;
        }
      } else {
        if (d-(n%d) == x)  {
          ans++;
        }
      }
    }
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
