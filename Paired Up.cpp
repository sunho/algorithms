#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  int m = 0;
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
    m += A[i].first;
  }
  sort(begin(A),end(A),[&](auto a, auto b){
    return a.second < b.second;
  });
  int rem = m/2;
  int r = n-1;
  int ans = 0;
  for (int i=0;i<n&&rem>0;i++) {
    int k = min(rem, A[i].first);
    rem -= k;
    while (k) {
      int t = min(A[r].first, k);
      ans = max(ans, A[i].second + A[r].second);
      A[r].first -= t;
      k -= t;
      if (A[r].first == 0) {
        r--;
      }
    }
  }
  cout << ans;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
