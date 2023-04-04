#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  multiset<pair<int,int>> left, right;
  for (int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    left.insert({a,b});
    right.insert({b,a});
  }
  int ans = 0;
  while (!left.empty()) {
    auto [s,t] = *left.begin();
    left.erase(left.begin());
    right.erase(right.find({t,s}));
    if (!right.empty()) {
      auto [y,x] = *right.begin();
      if (t > y) {
        continue;
      }
    }
    for (auto it = left.begin(); it != left.end();){
      auto [x,y] = *it;
      if (t > x) {
        it = left.erase(it);
        right.erase(right.find({y,x}));
      } else {
        break;
      }
    }
    ans++;
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
