#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector A(n, vector(n, 0));
  vector pf(n+1, vector(n+1, 0));
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      char c;
      cin >> c;
      int d = (int)(c == '*');
      A[i][j] = d;
    }
  }
  for (int i=1;i<=n;i++){
    for (int j=1;j<=n;j++){
      pf[i][j] = A[i-1][j-1] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
    }
  }
  while (m--){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    --a,--b,--c,--d;
    int res = pf[c+1][d+1] - pf[a][d+1] - pf[c+1][b] + pf[a][b];
    cout << res << "\n";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
