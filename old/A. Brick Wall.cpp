#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  if (m % 2 == 0) {
    cout << n*m/2 << "\n";
  } else {
    cout << n*(m-1)/2 << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
