#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n = 10;
  vector<vector<int>> A(n, vector<int>(n));
  vector<string> M(n, "..........");
  M[2] = "####.##.##";
  M[4] = "###.###.##";
  M[6] = "#.#.#.....";
  pair<int,int> ed;
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cin >> A[i][j];
      if (A[i][j] == 100) {
        ed = {i,j};
      }
    }
  }
  M[0][ed.second] = '#'; 
  for (int i=0;i<n;i++){
    cout << M[(i-ed.first+n)%n] << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
