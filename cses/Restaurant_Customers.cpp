#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }
  sort(begin(A), end(A));
  priority_queue<int> pq;
  int ans = 0;
  int cur = 0;
  for (int i=0;i<n;i++){
    auto [s,t] = A[i];
    while (!pq.empty() && -pq.top() <= s) {
      --cur;
      pq.pop();
    }
    ++cur;
    ans = max(ans, cur);
    pq.push(-t);
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
