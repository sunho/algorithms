#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }
  set<pair<int,int>> B;
  for (int i=0;i<n;i++){
    auto [l,r] = A[i];
    if (B.empty()) {
      B.insert({l,r});
      continue;
    }
    auto it = B.lower_bound({l,-1});
    if (it != B.begin()) {
      --it;
      auto [l2, r2] = *it;
      if (r2 >= l) {
        if (r <= r2) {
          continue;
        }
        l = r2+1;
      }
    }
    int sz = r-l+1; 
    while (sz) {
      auto it = B.lower_bound({l,-1});
      if (it == B.end()) break;
      auto [l2,r2] = *it;
      int k = min(r2-l2+1,sz);
      sz -= k;
      B.erase(it);
      l2 += k;
      if (k != r2-l2+1) {
        B.insert({l2,r2});
      }
    }
    B.insert({l,r});
  }
  int ans = 0;
  for (auto [l,r] : B) {
    ans += r-l+1;
  }
  cout << ans;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
