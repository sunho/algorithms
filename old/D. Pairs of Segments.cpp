#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  vector<int> vals;
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
    vals.push_back(A[i].first);
    vals.push_back(A[i].second);
  }
  sort(begin(vals),end(vals));
  vals.resize(unique(begin(vals),end(vals))-vals.begin());
  vector<vector<int>> starts(vals.size());
  for (int i=0;i<n;i++){
    A[i].first = lower_bound(begin(vals), end(vals), A[i].first) - vals.begin();
    A[i].second= lower_bound(begin(vals), end(vals), A[i].second) - vals.begin();
    starts[A[i].first].push_back(i);
  }
  vector<int> dp(vals.size()+1);
  for (int i=0;i<vals.size();i++){
    dp[i+1] = max(dp[i+1], dp[i]);
    for (int j : starts[i]) {
      for (int z=0;z<n;z++){
        if (z == j) continue;
        if (max(A[z].first,A[j].first) <= min(A[z].second,A[j].second) && A[j].first <= A[z].first) {
          int nx = max(A[z].second+1,A[j].second+1);
          dp[nx] = max(dp[nx], dp[i] + 2);
        }
      }
    }
  }
  cout << n - dp[vals.size()] << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
