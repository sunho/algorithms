#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  map<int,int> cnt;
  for (int i=0;i<2*n;i++){
    int a;
    cin >> a;
    cnt[a]++;
  }
  set<int> cnt2;
  for (auto [a, c] : cnt) {
    if (c%2 == 1) {
      if (m % 2 == 1) {
        cout << "Alice" << "\n";
        return;
      }
      cnt2.insert(a);
    }
  }
  for (auto a : cnt2) {
    if (!cnt2.count((a + m/2)%m)) {
      cout << "Alice" << "\n";
      return;
    }
  }
  if ((cnt2.size()/2) % 2 == 1) {
    cout << "Alice" << "\n";
    return;
  }
  cout << "Bob" << "\n";
}

// 1 2 3 4
// 0 2
// 1 3
// 0 1
// 2 3
// a + b = c + d
// a + d = c + b
// b - d = d - b
// 2b = 2d

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
