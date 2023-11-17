#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    vector<vector<char>> M(8, vector<char>(8));
    for (int i=0;i<8;i++) {
      for (int j=0;j<8;j++) {
        cin >> M[i][j];
      }
    }
    for (int j=0;j<8;j++){
      string s;
      for (int i=0;i<8;i++){
        if (M[i][j] != '.')
          s += M[i][j];
      }
      if (s != "") {
        cout << s << "\n";
      }
    }
  }
}
