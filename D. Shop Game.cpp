#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i].first;
  }
  for (int i=0;i<n;i++){
    cin >> A[i].second;
  }
  vector<pair<int,int>> B;
  for (int i=0;i<n;i++){
    B.push_back({-A[i].second,max(0,A[i].second-A[i].first)});
  }
  sort(rbegin(B),rend(B));
  n = (int)B.size();
  ll cc = 0;
  ll sum = 0;
  for (int i=0;i<k;i++){
    cc+=B[i].first;
    sum+=B[i].second;
  }
  ll ans = 0;
  for (int i=k;i<n;i++){
    sum += B[i].second;
    cc -= B[i-k].first;
    cc += B[i].first;
    ans = max(ans, cc+sum);
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
