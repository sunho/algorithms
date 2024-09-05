#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  ll x;
  cin >> x;
  set<int> rem;
  for (int i=1;i<=n;i++){
    rem.insert(i);
  }
  rem.erase(n-1);
  rem.erase(n);
  vector<int> ans;
  ans.push_back(n-1);
  for (int i=n-2;i>=1;i--){
    if (x >= i) {
      ans.push_back(n-1-i);
      rem.erase(n-1-i);
      x -= i;
    }
  }
  ans.push_back(n);
  if (x) {
    cout << -1 << "\n";
    return;
  }
  while (!rem.empty()) {
    ans.push_back(*--rem.end());
    rem.erase(--rem.end());
  }
  for (int a : ans) {
    cout << a << " ";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
