#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  const int inf = 1e9;
  array<int,3> ans = {inf,0,0};
  for (int i=0;i*5<=n;i++){
    if ((n-5*i)%3 == 0) {
      int j =(n-5*i)/3;
      ans = min(ans, {max(i,j),i,j});
    }
  }
  if (ans[0] == inf) {
    cout << -1 << "\n";
  } else {
    int x = ans[1], y = ans[2];
    for (int i=0;i<max(x,y)-min(x,y);i++){
      cout << (x > y ? '5' : '3');
    }
    for (int i=0;i<min(x,y);i++) {
      cout << '8';
    }
    cout << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
