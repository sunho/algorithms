#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<tuple<int,int,int>> A(n);
  vector<int> nums;
  for (int i=0;i<n;i++){
    int a,b,c;
    cin >> a >> b >> c;
    A[i] = {a,b,c};
    nums.push_back(a);
    nums.push_back(b);
  }
  sort(begin(nums), end(nums));
  nums.resize(unique(begin(nums), end(nums))-begin(nums));
  for (int i=0;i<n;i++){
    auto [a,b,c] = A[i];
    int na = lower_bound(begin(nums), end(nums), a) - begin(nums);
    int nb = lower_bound(begin(nums), end(nums), b) - begin(nums);
    A[i] = {na,nb,c};
  }
  int N = nums.size();
  vector<ll> dp(N+1);
  sort(begin(A),end(A));
  int l = 0;
  ll maxi = 0;
  for (int i=0;i<n;i++){
    auto [a,b,w] = A[i];
    for (; l < a; l++) {
      maxi = max(maxi, dp[l]);
    }
    dp[b] = max(dp[b], maxi + w);
  }
  for (; l <= N; l++) {
    maxi = max(maxi, dp[l]);
  }
  cout << maxi << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
