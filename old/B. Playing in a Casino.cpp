#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> A(m, vector<int>(n));
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++){
        cin >> A[j][i];
      }
    }
    ll ans = 0;
    for (int i=0;i<m;i++) {
      sort(rbegin(A[i]),rend(A[i]));
      ll sum = 0;
      for (int j=0;j<n;j++) {
        ans += sum - (ll)A[i][j]*j;
        sum += A[i][j];
      }
    }
    cout << ans << "\n";
  }
}
