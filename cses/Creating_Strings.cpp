#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  set<string> ans;
  vector<bool> used(s.size());
  string cand;
  auto dfs = [&](int i, auto&& self) {
    if (i == s.size()) {
      ans.insert(cand);
      return;
    }
    for (int j=0;j<s.size();j++){
      if (!used[j]) {
        used[j] = true;
        cand.push_back(s[j]);
        self(i+1, self);
        cand.pop_back();
        used[j]= false;
      }
    }
  };
  dfs(0,dfs);
  cout << ans.size() << "\n";
  for (string t : ans) { 
    cout << t << "\n";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
