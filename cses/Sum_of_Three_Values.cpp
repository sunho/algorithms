#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, x;
  cin >> n >> x;
  set<pair<int,int>> S;
  vector A(n, 0);
  for (int i=0;i<n;i++){
    cin >> A[i];
    S.insert({A[i], i});
  }
  for (int i=0;i<n;i++){
    S.erase({A[i], i});
    for (int j=i+1;j<n;j++) {
      int rem = x-A[i]-A[j];
      if (rem > 0) {
        auto it = S.upper_bound({rem, j});
        if (it != S.end()) {
          if (it->first == rem) {
            cout << i + 1 << " " << j + 1 << " " << it->second + 1 << "\n";
            return;
          }
        }
      }
    }
  }
  cout << "IMPOSSIBLE" << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
