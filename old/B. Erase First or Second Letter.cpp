#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  set<char> vis;
  ll ans = 0;
  for (int i=0;i<n;i++){
    if (vis.count(s[i])) continue;
    vis.insert(s[i]);
    ans += n-i;
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
