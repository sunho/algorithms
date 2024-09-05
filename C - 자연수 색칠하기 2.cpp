#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> ans(n+1);
  int k = 0;
  for (int i=1;i<=n;){
    if (i%2 == 1) {
      for (int j=i;j<=n&&j<=i+2;j++) {
        ans[j] = k+1;
      }
      k++;
      i += 3;
    } else {
      for (int j=i;j<=n&&j<=i+1;j++) {
        ans[j] = k+1;
      }
      k++;
      i += 2;
    }
  }
  cout << k << "\n";
  for (int i=1;i<=n;i++){
    cout << ans[i] << " ";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
