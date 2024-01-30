#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }
  vector<int> ans(n);
  auto go = [&](int s) {
    ans[0] = s;
    int cost = 0;
    for (int i=1;i<n;i++){
      if (s < A[i].first) {
        ans[i] = A[i].first;
        cost += A[i].first - s;
        s = A[i].first;
      } else if (s > A[i].second) {
        ans[i] = A[i].second;
        cost += s-A[i].second;
        s = A[i].second;
      } else {
        ans[i] = s;
      }
    }
    return cost;
  };
  array<int,2> mn = {(int)1e9, 0};
  for (int x=A[0].first;x<=A[0].second;x++) {
    mn = min(mn, {go(x),x});
  }
  cout << go(mn[1]) << "\n";
  for (int i=0;i<n;i++){
    cout << ans[i] << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
