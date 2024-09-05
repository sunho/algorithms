#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,k;
  cin >> n >> k;
  vector<int> cnt(k);
  set<pair<int,int>> cur;
  for (int i=0;i<k;i++){
    cin >> cnt[i];
    cur.insert({cnt[i],-i});
  }
  auto subtract = [&](int k) {
    auto it = cur.find({cnt[k],-k});
    cur.erase(it);
    cnt[k]--;
    if (cnt[k] != 0) {
      cur.insert({cnt[k],-k});
    }
  };
  vector<int> ans;
  while (!cur.empty()) {
    auto it = --cur.end();
    if (ans.empty()) {
      ans.push_back(-it->second);
      subtract(-it->second);
    } else {
      if (-it->second == ans.back()) {
        if (it == cur.begin()) {
          cout << -1 << "\n";
          return;
        }
        --it;
      }
      ans.push_back(-it->second);
      subtract(-it->second);
    }
  }
  for (auto x : ans) {
    cout << x + 1 << " ";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
