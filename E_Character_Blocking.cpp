#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string A[2];
  cin >> A[0] >> A[1];
  int n = A[0].size();
  int t, q;
  cin >> t >> q;
  set<int> falses;
  set<pair<int,int>> unblock;
  auto check = [&](int pos) {
    falses.erase(pos);
    if (A[0][pos] != A[1][pos]) {
      falses.insert(pos);
    }
  };
  for (int i=0;i<n;i++){
    check(i);
  }
  for (int i=0;i<q;i++){
    while (!unblock.empty() && unblock.begin()->first == i) {
      auto [_, j] = *unblock.begin();
      check(j);
      unblock.erase(unblock.begin());
    }
    int o;
    cin >> o;
    if (o == 1) {
      int x;
      cin >> x;
      --x;
      falses.erase(x);
      unblock.insert({i+t,x});
    } else if (o == 2) {
      int a, x, b, y;
      cin >> a >> x >> b >> y;
      --a,--x,--b,--y;
      swap(A[a][x], A[b][y]);
      check(x), check(y);
    } else {
      if (falses.empty()) {
        cout << "YES" << "\n";
      } else {
        cout << "NO" << "\n";
      }
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--){
    solve();
  }

}
