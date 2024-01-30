#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll n,k;
  cin >> n >> k;
  k = min(k, n-k);
  ll t = lcm(k,n)/k;
  cout << (k*t/n-1)*t << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
