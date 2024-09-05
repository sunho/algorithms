#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, l;
  cin >> n >> l;
  vector<pair<int,int>> A(n);
  vector<int> T;
  for (int i=0;i<n;i++){
    cin >> A[i].second >> A[i].first;
  }
  sort(begin(A),end(A));
  int ans = 0;
  for (int i=0;i<n;i++){
    map<int,int> S;
    int cur = 0;
    int cnt = 0;
    for (int j=i;j<n;j++){
      int delta = A[j].first - A[i].first;
      while (!S.empty() && cur + delta > l) {
        int k = (--S.end())->first;
        cur -= k;
        S[k] --;
        if (S[k] == 0) {
          S.erase(k);
        }
        cnt--;
      }
      if (cur + delta + A[j].second <= l) {
        S[A[j].second]++;
        cur += A[j].second;
        cnt++;
      } else if (!S.empty() && (--S.end())->first > A[j].second) {
        int k = (--S.end())->first;
        cur -= k;
        S[k] --;
        if (S[k] == 0) {
          S.erase(k);
        }
        S[A[j].second]++;
        cur += A[j].second;
      }
      ans = max(ans, cnt);
    }
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
