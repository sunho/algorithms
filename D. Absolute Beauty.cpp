#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> A(n);
  vector<int> B(n);
  vector<int> vals;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    A[i].first = a;
    vals.push_back(a);
  }
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    A[i].second = a;
    vals.push_back(a);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (A[i].first > A[i].second) {
      swap(A[i].first, A[i].second);
    }
    ans += abs(A[i].first - A[i].second);
  }
  sort(begin(A), end(A));
  set<int> S;
  ll cand = 0;
  for (int i = 0; i < n; i++) {
    auto [a, b] = A[i];
    S.insert(b);
    cand = max(cand, (ll)2 * (a - *S.begin()));
  }
  cout << ans + cand << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
