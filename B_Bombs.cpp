#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,m;
  cin >> n >> m;
  vector M(n, vector(m, ' '));
  vector<tuple<int,int,int>> bombs;
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> M[i][j];
      if (M[i][j] != '.' && M[i][j] != '#') {
        bombs.push_back({i,j,M[i][j]-'0'});
      }
    }
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      bool fill = M[i][j] == '#';
      for (auto [x,y,k] : bombs) {
        int d = abs(x-i) + abs(y-j);
        if (d <= k) {
          fill = false;
        }
      }
      if (fill) {
        cout << "#";
      } else {
        cout << ".";
      }
    }
    cout << "\n";
  }
}
