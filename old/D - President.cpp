#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> A(n), S(n);
  int sum = 0;
  for (int i=0;i<n;i++){
    int x,y,w;
    cin >> x >> y >> w;
    int k = (x + y + 1)/2;
    A[i] = max(k - x,0);
    S[i] = w;
    sum += w;
  }
  const ll inf = 1e18;
  vector<ll> dp(sum+1, inf);
  dp[0] = 0;
  for (int i=0;i<n;i++){
    vector<ll> nxt(sum+1, inf);
    for (int j=0;j<=sum;j++){
      if (j+S[i]<=sum) {
        nxt[j+S[i]] = min(nxt[j+S[i]], dp[j]+A[i]);
      }
      nxt[j] = min(nxt[j], dp[j]);
    }
    dp = nxt;
  }
  int k = (sum + 1)/2;
  ll ans = inf;
  for (int i=k;i<=sum;i++){
    ans = min(ans, dp[i]);
  }
  cout << ans << "\n";
}
