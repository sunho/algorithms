#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;

  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
    if (A[i].first > A[i].second) {
      swap(A[i].first, A[i].second);
    }
  }
  int d;
  cin >> d;
  sort(A.begin(),A.end(), [&](auto a, auto b) {
    return a.second < b.second;
  });
  int ans = 0;
  priority_queue<int, vector<int>, greater<>> pq;
  for (int i=0;i<n;i++){
    auto [l,r] = A[i];
    pq.push(l);
    while (!pq.empty() && pq.top() < r-d) {
      pq.pop();
    }
    ans = max(ans, (int)pq.size());
  }
  cout << ans;
}
