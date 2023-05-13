#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    vector<vector<int>> ans(2, vector<int>(n));
    for (int i=0;i<n;i++){
      ans[(i+1)%2][i] = i+1;
    }
    ans[0][0] = 2*n;
    ans[1][n-1] = 2*n-1;
    for (int i=1;i<n-1;i++){
      ans[i%2][i] = i+n;
    }
    for (int i=0;i<2;i++){
      for (int j=0;j<n;j++){
        cout << ans[i][j] << " ";
      }
      cout << "\n";
    }
  }
}
