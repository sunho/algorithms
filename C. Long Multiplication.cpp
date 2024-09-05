#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string x,y;
  cin >> x >> y;
  int n = (int)x.size();
  string xx,yy;
  for (int i=0;i<n;i++){
    char a = x[i], b = y[i];
    if (a > b) swap(a,b);
    if (i == 0) {
      yy = a;
      xx = b;
    } else {
      if (xx < yy) {
        xx = xx + b;
        yy = yy + a;
      } else {
        xx = xx + a;
        yy = yy + b;
      }
    }
  }
  cout << xx << "\n";
  cout << yy << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
