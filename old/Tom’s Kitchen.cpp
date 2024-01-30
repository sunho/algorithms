#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> A(n);
  const int MX = 300;
  int sum = 0;
  bool yes = true;
  for (int i=0;i<n;i++){
    cin >> A[i];
    if (A[i] < k) {
      yes = false;
    }
    sum += A[i];
  }
  vector<int> B(m);
  for (int i=0;i<m;i++){
    cin >> B[i];
  }
  if (!yes){
    cout << "Impossible" << "\n";
    return;
  }
  const int inf = 1e9;
  const int N = MX * n;
  vector<int> dp(N+1,inf);
  dp[0] = n*k;
  for (int i=0;i<m;i++){
    vector<int> nxt = dp;
    for (int j=0;j<N;j++){
      if (j + B[i] <= N) {
        nxt[j+B[i]] = min(nxt[j+B[i]],max(dp[j]-min(B[i],n),0));
      }
    }
    dp = nxt;
  }
  for (int i=0;i<=N;i++){
    if (dp[i] == 0 && i >= sum) {
      cout << i - sum << "\n";
      return;
    }
  }
  cout << "Impossible" << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
