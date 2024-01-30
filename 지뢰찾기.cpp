#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<vector<char>> M(n, vector<char>(n));
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cin >> M[i][j];
    }
  }
  vector<vector<char>> board(n, vector<char>(n));
  auto get = [&](int i, int j) -> int {
    if (i < 0 || i>=n || j <0 || j >=n) return 0;
    return board[i][j];
  };
  auto cnt = [&](int i, int j) {
    int res = 0;
    for (int x=i-1;x<=i+1;x++){
      for (int y=j-1;y<=j+1;y++){
        res += get(x,y);
      }
    }
    return res;
  };
  for (int i=1;i<n-1;i++){
    int c = M[i-1][0] - '0';
    if (cnt(i-1,0) < c) {
      board[i][1] = 1;
    }
  }
  for (int i=1;i<n-1;i++){
    int c = M[0][i-1] - '0';
    if (cnt(0,i-1) < c) {
      board[1][i] = 1;
    }
  }
  for (int i=1;i<n-1;i++){
    int c = M[n-1][i-1] - '0';
    if (cnt(n-1,i-1) < c) {
      board[n-2][i] = 1;
    }
  }
  for (int i=1;i<n-1;i++){
    int c = M[i-1][n-1] - '0';
    if (cnt(i-1,n-1) < c) {
      board[i][n-2] = 1;
    }
  }
  int ans = n>=4?(n-4)*(n-4):0;
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      ans += board[i][j];
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
