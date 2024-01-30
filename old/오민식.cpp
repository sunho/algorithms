#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// sieves + lp
// works when N <= 10^7
// O(n log n) time
vector<ll> lp;
vector<ll> pr;
void sieves(int PN) {
  lp.assign(PN+1,0);
  for (int i=2; i <= PN; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= PN; ++j) {
      lp[i * pr[j]] = pr[j];
    }
  }
}


// factor one number count p^k
// O(sqrt(n))
vector<pair<ll,int>> factorize(ll n) {
  vector<pair<ll,int>> facts;
  while (n > 1) {
    int k=0;
    int d = lp[n];
    while (n % d == 0) {
      n /= d;
      k++;
    }
    if (k != 0) {
      facts.push_back({d,k});
    }
  }
  return facts;
}

void solve() {
  int n;
  cin >> n;
  const ll mod = 987654321;
  ll ans = 1;
  map<int, int> mx;
  for (int i=1;i<=n;i++){
    auto fs = factorize(i);
    for (auto [p, c] : fs) {
      mx[p] = max(c, mx[p]);
    }
  }
  for (auto [p,c]: mx) {
    while (c--) {
      ans *= p;
      ans %= mod;
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  const int N = 1e6;
  sieves(N);
  solve();
}
