#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  map<int,int> cnt;
  for (int i=0;i<n*n;i++){
    int a;
    cin >> a;
    cnt[a]++;
  }
  vector<int> ans;
  auto subtract = [&](int a) {
    cnt[a]--;
    if (cnt[a] == 0) {
      cnt.erase(a);
    }
  };
  while ((int)ans.size() < n) {
    auto [a, c] = *--cnt.end();
    for (int x : ans) {
      subtract(gcd(x,a));
      subtract(gcd(x,a));
    }
    if (cnt.count(a)) {
      ans.push_back(a);
      subtract(a);
    } else {
      cout << -1 << "\n";
      return;
    }
  }
  for (int x : ans) {
    cout << x << " ";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
