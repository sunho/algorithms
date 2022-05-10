#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)

void solve() {
  int n,w;
  cin >> n >> w;
  vector<pair<int,int>> items(n);
  for(int i=0;i<n;i++){
    cin >> items[i].first >> items[i].second;
  }
  sort(all(items), greater<>());
  ll ans = 0;
  for(int i=0;i<n;i++){
    int k = min(w, items[i].second);
    w -= k;
    ans += (ll)k*items[i].first;
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
