#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> A(n);
  map<char,int> cvt = {{'R',0},{'G',1},{'B',2}};
  map<int,char> icvt = {{0,'R'},{1,'G'},{2,'B'}};
  for (int i=0;i<n;i++){
    A[i] = cvt[s[i]];
  }
  const int inf = 1e9;
  vector<array<int,3>> dp(n+1, array<int,3>{inf,inf,inf});
  vector<array<int,3>> prev(n+1, array<int,3>{-1,-1,-1});
  dp[0][0] = dp[0][1] = dp[0][2] = 0;
  for (int i=0;i<n;i++){
    for (int j=0;j<3;j++){
      for (int k=0;k<3;k++){
        if (j == k) continue;
        int cost = dp[i][j];
        if (k != A[i]){
          cost++;
        }
        if (dp[i+1][k] > cost) {
          dp[i+1][k] = cost;
          prev[i+1][k] = j;
        }
      }
    }
  }
  
  int col = min_element(begin(dp[n]),end(dp[n])) - begin(dp[n]);
  cout << dp[n][col] << "\n";
  vector<int> ans;
  for (int i=n;i>=1;i--){
    ans.push_back(col);
    col = prev[i][col];
  }
  reverse(begin(ans),end(ans));
  for (int i=0;i<n;i++){
    cout << icvt[ans[i]];
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
