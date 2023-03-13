#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector A(n,0);
  for (int i=0;i<n;i++)
    cin >> A[i];
  int ans = 0;
  multiset<int> towers;
  for (int i=0;i<n;i++){
    auto it = towers.upper_bound(A[i]);
    if (it == towers.end()) {
      ans++;
      towers.insert(A[i]);
    } else {
      towers.erase(it);
      towers.insert(A[i]);
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
