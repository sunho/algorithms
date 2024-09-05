#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> B(n);
  for (int i=0;i<n;i++){
    cin >> B[i];
  }
  int ans = n+1;
  int mn = *min_element(begin(B),end(B));
  int mx = *max_element(begin(B),end(B));
  {
    auto A = B;
    int k = (int)(find(begin(A),end(A),mn)-begin(A));
    rotate(begin(A), begin(A)+k,end(A));
    if (is_sorted(begin(A),end(A))) {
      ans = min(ans, k);
    }
  }
  {
    auto A = B;
    int k = (int)(find(begin(A),end(A),mx)-begin(A));
    rotate(begin(A), begin(A)+k,end(A));
    if (is_sorted(rbegin(A),rend(A))) {
      ans = min(ans, k);
    }
  }
  if (ans == n+1) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
