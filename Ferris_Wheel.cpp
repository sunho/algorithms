#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  int x;
  cin >> x;
  multiset<int> S;
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    S.insert(a);
  }
  int ans = 0;
  while (!S.empty()){
    int cur = *S.begin();
    S.erase(S.begin());
    ans++;
    auto it = S.upper_bound(x-cur);
    if (it == S.begin()) {
      continue;
    }
    S.erase(--it);
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
