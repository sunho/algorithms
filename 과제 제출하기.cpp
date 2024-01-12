#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> D(n);
  for (int i = 0; i < n; i++) {
    cin >> D[i];
  }
  vector<vector<int>> A(m);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int a;
      cin >> a;
      --a;
      A[i].push_back(a);
    }
  }
  vector<int> order(m);
  iota(begin(order), end(order), 0);
  int ans = 1e9;
  do {
    vector<int> rem(n);
    int cand = 0;
    for (int i = 0; i < m; i++) {
      for (int a : A[order[i]]) {
        if (rem[a] == 0) {
          rem[a] = D[a];
          cand++;
        }
      }
      for (int j = 0; j < n; j++) {
        rem[j]--;
        rem[j] = max(rem[j], 0);
      }
    }
    ans = min(ans, cand);
  } while (next_permutation(begin(order), end(order)));
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
