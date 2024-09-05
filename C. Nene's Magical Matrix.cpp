#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i=1;i<=n;i++){
    sum += i*(2*i-1);
  }
  cout << sum << " " << 2*n << "\n";
  for (int i=n;i>=1;i--){
    for (int c : {1,2}) {
      cout << c << " " << i << " ";
      for (int j=1;j<=n;j++){
        cout << j << " ";
      }
      cout << "\n";
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
