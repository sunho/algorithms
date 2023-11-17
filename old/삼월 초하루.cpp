#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> tgt(2);
  for (int i=0;i<2;i++){
    cin >> tgt[i];
    tgt[i] /= 5;
  }
  vector<int> A(2, 20);
  vector<int> B(3);
  for (int i=0;i<3;i++){
    cin >> B[i];
    if (B[i] == 2) {
      B[i] = 1;
    } else if (B[i] == 1) {
      B[i] = 0;
    } else {
      B[i] = -1;
    }
  }
  vector<pair<int,int>> ans;
  vector<int> C(3);
  C[0] = 0, C[1] = 1, C[2] = -1;
  auto mov = [&](int u, int v) {
    assert(C[u] != -1 && C[v] == -1);
    if (A[C[u]] - 1 < tgt[C[u]]) {
      return 0;
    }
    A[C[u]]--;
    swap(C[u], C[v]);
    ans.push_back({u,v});
    return 1;
  };
  auto shuffle = [&](int u) {
    assert(C[u] != -1);
    int v = find(begin(C),end(C),-1) - begin(C);
    if ((A[C[u]]-tgt[C[u]])%2==1) {
      return 0;
    }
    for (int i=0;i<(A[C[u]]-tgt[C[u]])/2;i++){
      ans.push_back({u,v});
      ans.push_back({v,u});
    }
    return 1;
  };
  int lvl = 0;
  auto dfs = [&](auto&& self) -> void {
    if ((A[0] - tgt[0]) % 2 == 0 && (A[1] - tgt[1]) % 2 == 0 && B == C) {
      for (int i=0;i<3;i++){
        if (C[i] != -1) {
          shuffle(i);
        }
      }
      cout << ans.size() << "\n";
      for (auto [u,v] : ans) {
        cout << u + 1 << " " << v + 1 << "\n";
      }
      exit(0);
    }
    if (lvl == 10) {
      return;
    }
    int v = find(begin(C),end(C),-1) - begin(C);
    for (int i=0;i<2;i++){
      int u = find(begin(C),end(C),i) - begin(C);
      if (mov(u, v)) {
        lvl++;
        self(self);
        swap(C[u],C[v]);
        A[C[u]]++;
        ans.pop_back();
        lvl--;
      }
    }
  };
  dfs(dfs);
  cout << -1 << "\n";
}
