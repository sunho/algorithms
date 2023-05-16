#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  
  vector<vector<int>> A(n, vector<int>(n));
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cin >> A[i][j];
    }
  }
  int cnt = 0;
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (A[i][j] != A[n-i-1][n-j-1]) {
        cnt++;
      }
    }
  }
  cnt/=2;
  if (cnt > k || (n%2 == 0 && (k-cnt)%2 != 0)) {
    cout << "NO" << "\n";
  } else {
    cout << "YES" << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);


  int t;
  cin >> t;
  while(t--) solve();
}
