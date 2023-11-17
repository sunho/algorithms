#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    vector<pair<int,int>> A(n);
    for (int i=0;i<n;i++){
      cin >> A[i].first >> A[i].second;
    }
    sort(begin(A), end(A), [&](auto a, auto b) {
      return make_pair(a.first, -a.second) < make_pair(b.first, -b.second);
    });
    vector<int> ban(n+1);
    ll ans = 0;
    map<int, int> cnt;
    int cur = 0;
    for (int i=0;i<n;i++){
      auto [a,b] = A[i];
      if (!ban[a]) {
        cur += 1;
        cnt[a] += 1;
        ans += b;
        if (!ban[cur]) {
          ban[cur] = 1;
          cur -= cnt[cur];
          cnt[cur] = 0;
        }
      }
    }
    cout << ans << "\n";
  }
}
