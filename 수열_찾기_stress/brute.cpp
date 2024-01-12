#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<vector<int>> S = {{}};
  for (int i=0;i<n-2;i++){
    vector<vector<int>> to_insert;
    for (int j=10;j<=13;j++){
      for(auto C : S) {
        C.push_back(j);
        to_insert.push_back(C);     
      }
    }
    S = to_insert;
  }
  bool ok = false;
  vector<vector<int>> B;
  auto dfs = [&](auto&& self) -> void {
    if (B.size() == n) {
      vector<int> sum(n);
      for (int i=0;i<n;i++){
        for (int j=0;j<n-2;j++){
          sum[j] += B[i][j];
        }
      }
      bool yes = true;
      set<vector<int>> SS;
      for (int i=0;i<n;i++){
        SS.insert(B[i]);
        for (int j=0;j<n-2;j++) {
          if ((B[i][j])*(A[i]+1) < sum[j]) {
            yes = false;
          }
        }
      }
      if (SS.size() != n) {
        yes = false;
      }
      if (yes) {
        ok = true;
        /* for (auto C: B) { */
        /*   for (int a : C) { */
        /*     cout << a << " "; */
        /*   } */
        /*   cout << "\n"; */
        /* } */
      }
      return;
    }
    for (auto C : S) {
      B.push_back(C);
      self(self);
      B.pop_back();
    }
  };
  dfs(dfs);
  if (ok) {
    cout << 1;
  } else {
    cout << 0;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}

