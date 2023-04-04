#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector A(n, 0);
  for(int i=0;i<n;i++) cin >> A[i];
  ll inf = 1e9;
  ll ans = -inf;
  ll cur = 0;
  for (int l=0;l<n;l++){
    cur += A[l];
    ans = max(ans, cur);
    if (cur < 0) 
      cur = 0;
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
