#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,k;
  cin >> n >> k;
  vector A(n,0);
  vector sel(n+1, -1);
  vector S(n+1, vector<int>());
  for (int i=0;i<n;i++){
    cin >> A[i];
    S[A[i]].push_back(i);
    if (sel[A[i]] == -1) {
      sel[A[i]] = i;
    }
  }
  set<int> vis;
  vis.insert(sel[1]);
  for (int i=2;i<=k;i++){
    auto it = upper_bound(begin(S[i]), end(S[i]), *--vis.end());
    if (it != S[i].end()) {
      sel[i] = *it;
    } else {
      if (it != S[i].begin()) {
        --it;
        int x = *it;
        if (x > *vis.begin()) {
          auto jt = --vis.upper_bound(x);
          sel[i] = *upper_bound(begin(S[i]), end(S[i]), *jt);
        }
      }
    }

    vis.insert(sel[i]);
  }
  for (int v : vis) {
    cout << A[v] << " ";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
