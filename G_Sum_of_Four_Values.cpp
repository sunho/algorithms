#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  ll x;
  cin >> n >> x;
  vector A(n, 0ll);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  map<int, pair<int,int>> M;
  for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){
      int rem = x - A[i] - A[j];
      if (rem <= 0) continue;
      auto it = M.find(rem);
      auto [k,z] = it->second;
      if (it != M.end()) {
        cout << k + 1 << " " << z + 1 << " " << i + 1 << " " << j + 1 << "\n";
        return;
      }
    }
    for (int j=0;j<i;j++){
      M[A[i]+A[j]] = {i,j};
    }
  }
  cout << "IMPOSSIBLE";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
