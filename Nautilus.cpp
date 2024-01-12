#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,m,k; 
  cin >> n >> m >> k;
  const int N = 500;
  using BS = bitset<N>;
  vector<BS> A(n);
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      char c;
      cin >> c;
      A[i][j] = c == '.';
    }
  }
  string s;
  cin >> s;
  vector<BS> dp = A;
  for (int i=0;i<k;i++) {
    vector<BS> nxt(n);
    if (s[i] == 'S' || s[i] == '?') {
      for (int j=0;j<n-1;j++) {
        nxt[j+1] |= (dp[j] & A[j+1]);
      }
    }
    if (s[i] == 'N' || s[i] == '?') {
      for (int j=1;j<n;j++) {
        nxt[j-1] |= (dp[j] & A[j-1]);
      }
    }
    if (s[i] == 'W' || s[i] == '?') {
      for (int j=0;j<n;j++) {
        nxt[j] |= ((dp[j] >> 1) & A[j]);
      }
    }
    if (s[i] == 'E' || s[i] == '?') {
      for (int j=0;j<n;j++) {
        nxt[j] |= ((dp[j] << 1) & A[j]);
      }
    }
    dp = nxt;
  }
  int cnt = 0;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++){
      cnt += dp[i][j];
    }
  }
  cout << cnt << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
