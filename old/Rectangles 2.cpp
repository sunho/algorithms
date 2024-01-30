#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,m,p;
  cin >> n >> m >> p;
  ll ans = 0;
  for (int x=1;x<=n;x++){
    for (int y=1;y<=m;y++){
      if (2*(x+y) >= p) {
        ans += (n-x+1)*(m-y+1);
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
