#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int m = n-2;
  int leaf = 2;
  ll ans = (ll)2*(m/2)*(m-m/2);
  cout << ans << "\n";
  vector<pair<int,int>> adj;
  cout << 1 << " " << 2 << "\n";
  for (int i=0;i<m/2;i++) {
    cout << leaf << " " << ++leaf << "\n";
  }
  int rem = m - m/2;
  for (int i=0;i<rem;i++){
    cout << 1 << " " << ++leaf << "\n";
  }
}
