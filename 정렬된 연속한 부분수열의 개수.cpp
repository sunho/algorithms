#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >>n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  int cnt = 1;
  ll ans = 0;
  for (int i=1;i<n;i++){
    if (A[i-1]<A[i]) {
      cnt++;
    } else {
      ans += (ll)cnt*(cnt+1)/2;
      cnt = 1;
    }
  }
  ans += (ll)cnt*(cnt+1)/2;
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
