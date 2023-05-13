#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> A(n, vector<int>(n));
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      char c;
      cin >> c;
      A[i][j] = c - '0';
    }
  }

  string ans = "";

  auto dfs = [&](int i, int j, pair<int,int> dir) {
    string cand;
    for (int t=0;t<n;t++){
      cand.push_back(A[i][j] + '0');
      i+=dir.first;
      j+=dir.second;
      i = (i + n) % n;
      j = (j + n) % n;
    }
    ans = max(ans, cand);
  };

  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      for (int dx=-1;dx<=1;dx++){
        for (int dy=-1;dy<=1;dy++){
          if (dx == 0 && dy == 0) continue;
          dfs(i,j,{dx,dy});
        }
      }
    }
  }
  cout << ans << "\n";
}