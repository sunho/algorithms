#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  ll x;
  cin >> x;
  const ll MOD = 998244353;
  cout << ((x % MOD) + MOD) % MOD; 
}
