#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<vector<string>> A(n);

  for (int i=0;i<n;i++){
    int m;
    cin >> m;
    for (int j=0;j<m;j++){
      string s;
      cin >> s;
      A[i].push_back(s);
    }
  }

  bool ok = true;
  set<string> vis;
  auto dfs = [&](auto&& self, vector<vector<string>> cur) {
    if (cur.size() == 0 || (cur.size() == 1 && cur[0].size() == 0)) {
      return;
    }
    map<string,int> cnt;
    pair<int,string> mx={-1,""};
    for (auto& arr : cur) {
      for (string s : arr) {
        cnt[s]++;
        mx = max(mx, {cnt[s],s});
      }
    }
    vector<vector<string>> L, R;
    if (vis.count(mx.second)) {
      ok = false;
    }
    vis.insert(mx.second);
    for (auto& arr : cur) {
      vector<string> nw;
      bool ins = false;
      for (string s : arr) {
        if (s == mx.second) {
          ins = true;
        } else {
          nw.push_back(s);
        }
      }
      if (ins) {
        L.push_back(nw);
      } else {
        R.push_back(nw);
      }
    }
    self(self, L);
    self(self, R);
  };
  dfs(dfs,A);
  if (ok) {
    cout << "yes" << "\n";
  } else {
    cout << "no" << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
