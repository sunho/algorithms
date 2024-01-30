#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;
  int t;
  cin >> t;
  while (t--) {
    string a;
    cin >> a;
    int n = a.size();
    vector<int> dp(s.size()+1);
    dp[0] = 1;
    for (int i=0;i<n;i++){
      vector<int> nxt(s.size()+1);
      for (int j=0;j<s.size();j++){
        if (s[j] == a[i]) {
          nxt[j+1] |= dp[j];
        }
        if (s[j] == '*') {
          nxt[j] |= dp[j];
          nxt[j+1] |= (dp[j]||nxt[j]);
          dp[j+1] |= dp[j];
        }
      }
      dp = nxt;
    }
    if (dp[s.size()]) {
      cout << a << "\n";
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
