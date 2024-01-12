#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<tuple<int,int,int>> A(n);
  for (int i=0;i<n;i++){
    int c,f,v;
    cin >> c >> f >> v;
    A[i] = {f,v,c};
  }
  sort(rbegin(A),rend(A));
  int m;
  cin >> m;
  vector<tuple<int,int,int>> B(m);
  for (int i=0;i<m;i++){
    int c,f,v;
    cin >> c >> f >> v;
    B[i] = {f,v,c};
  }
  sort(rbegin(B),rend(B));
  int ptr = 0;
  const ll inf = 1e18;
  const int N = n*50;
  vector<ll> dp(N+1, -inf);
  dp[0] = 0;
  for (int i=0;i<m;i++){
    auto [f,v,c] = B[i];
    while (ptr < n && get<0>(A[ptr]) >= f) {
      auto [f2,v2,c2] = A[ptr];
      for (int j=N;j>=0;j--){
        if (j-c2 >= 0) {
          dp[j] = max(dp[j], dp[j-c2]-v2);
        }
      }
      ptr++;
    }
    for (int j=0;j<=N;j++) {
      if (j + c <= N) {
        dp[j] = max(dp[j], dp[j+c]+v);
      }
    }
  }
  cout << *max_element(begin(dp),end(dp)) << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
