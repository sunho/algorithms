#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,q;
  cin >> n >> q;
  vector<int> copy;
  vector<ll> str;
  vector<vector<int>> A;
  A.push_back({});
  str.push_back(0);
  const ll N = 1e18;
  int last = 0;
  for (int i=0;i<n;i++) {
    int a,x;
    cin >> a >> x;
    if (last != 0 && str.back() >= N) {
      continue;
    }
    if (a == 1) {
      A[last].push_back(x);
    } else {
      ++x;
      copy.push_back(x);
      str.push_back(0);
      if (last != 0) {
        str[last+1] = min(((__int128_t)A[last].size() + str[last]) * x, (__int128_t)N);
      } else {
        str[last+1] = min((__int128_t)A[last].size() * x, (__int128_t)N);
      }
      last++;
      A.push_back({});
    }
  }
  while (q--) {
    ll k;
    cin >> k;
    --k;
    int cur = last;
    while (k < str[cur]) {
      k %= (ll)(str[cur-1]+A[cur-1].size());
      cur--;
    }
    cout << A[cur][k-str[cur]] << " ";
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
