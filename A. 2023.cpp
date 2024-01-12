#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  map<int,int> cnt;
  bool ok = true;
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  ll prod = 1;
  for (int i=0;i<n;i++) {
    prod *= A[i];
  }
  if (prod > 2023 || 2023 % prod != 0) {
    cout << "NO" << "\n";
    return;
  }
  if (prod != 2023 && k == 0) {
    cout << "NO" << "\n";
    return;
  }
  cout << "YES" << "\n";
  if (k > 0) {
    cout << 2023/prod << " ";
    for (int i=0;i<k-1;i++){
      cout << 1 << " ";
    }
    cout << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
  solve();
}
