#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<char>> M(n, vector<char>(n));
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      cin >> M[i][j];
    }
  }
  bool ok = false;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (M[i][j] == '#') {
        ok = true;
      }
    }
  }
  if (!ok) {
    cout << -1 << "\n";
    return 0;
  }
  const int inf = 1e9;
  int ans = inf; 
  int filled = 0;
  for (int j=0;j<n;j++){
    int cnt2 = 0;
    for (int k=0;k<n;k++){
      cnt2 += M[k][j] == '#';
    }
    if (cnt2 == n) {
      filled++;
    }
  }
  for (int i=0;i<n;i++) {
    bool found = false;
    for (int j=0;j<n;j++) {
      if (M[j][i] == '#') {
        found = true;
      }
    }
    int cnt = 0;
    for (int j=0;j<n;j++) {
      if (M[i][j] == '#') {
        cnt++;
      }
    }
    int cost = n - cnt;
    cost += n - filled;
    if (!found) {
      cost++;
    }
    ans = min(ans, cost);
  }
  if (ans == inf) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
}
