#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, remove, add;
  cin >> n >> remove >> add;
  map<int, int> cnt;
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    cnt[a]++;
  }

  ll cost = 0;
  const ll inf = (ll)1e18+1;
  ll ans = inf;
  int last = 0;
  stack<int> pf;
  pf.push(0);
  ll cand = 0;
  for (auto it = cnt.rbegin(); it != cnt.rend(); it++) {
    pf.push(pf.top() + it->second);
    cand += (ll)remove*it->second;
  }
  cand += add;
  ans = cand;
  pf.pop();
  for (auto [a, c] : cnt) {
    int rem = pf.top();
    pf.pop();
    cost += (ll)(a-last-1)*add;
    cost += (ll)(c-1)*remove;
    last = a;
    ans = min(ans, cost + (ll)(rem)*remove);
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
