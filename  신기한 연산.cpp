#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i=0;i<m;i++){
    cout << (char)('a' + (i/2)%n);
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
