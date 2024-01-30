#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int q;
  cin >> q;
  string t;
  cin >> t;
  vector<vector<char>> dp(q, vector<char>(q));
  vector<int> stk;
  int n = 0;
  string S;
  ll cur = 0;
  for (int i=0;i<q;i++){
    if (t[i] == '-') {
      n--;
      cur -= stk.back();
      stk.pop_back();
      S.pop_back();
      cout << cur << " \n"[i==q-1];
    } else {
      S.push_back(t[i]);
      n++;
      dp[n-1][n-1] = true;
      int k = 1;
      for (int j=0;j<n-1;j++){
        dp[j][n-1] = false;
        if (S[n-1] == S[j]) {
          if (j+1 > n-2) {
            dp[j][n-1] = true;
          } else {
            dp[j][n-1] = dp[j+1][n-2];
          }
        }
        if (dp[j][n-1]) k++;
      }
      cur += k;
      stk.push_back(k);
      cout << cur << " \n"[i==q-1];
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
