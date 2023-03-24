#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector dp(n, vector(n, array<ll, 2>{-1ll,-1ll}));
  auto dfs = [&](int l, int r, auto && self) -> array<ll,2> {
    if (dp[l][r][0] != -1) return dp[l][r];
    int i = n - r - 1 + l;
    int t = i%2;
    if (l==r) {
      if (i % 2 == 0)
        return {A[l],0};
      else
        return {0,A[l]};      
    }
    array<ll,2> cand1 = self(l+1,r,self);
    cand1[t] += A[l];
    array<ll,2> cand2 = self(l,r-1,self);
    cand2[t] += A[r];
    if (cand1[t] > cand2[t]) {
      return dp[l][r] = cand1;
    } else {
      return dp[l][r] = cand2;
    }
  };
  cout << dfs(0,n-1,dfs)[0] << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
