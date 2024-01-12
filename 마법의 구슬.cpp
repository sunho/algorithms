#include <bits/stdc++.h>

using namespace std;
using ll = long long;


vector<ll> lp, pr;

// sieves + lp
// works when N <= 10^7
// O(n log n) time
void sieves(int PN) {
  lp.assign(PN + 1, 0);
  for (int i = 2; i <= PN; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= PN;
         ++j) {
      lp[i * pr[j]] = pr[j];
    }
  }
}

// factor one number count p^k
// O(sqrt(n))
vector<pair<ll, int>> factorize(ll n) {
  vector<pair<ll, int>> facts;
  while (n > 1) {
    int k = 0;
    int p = lp[n];
    while (n % p == 0) {
      n /= p;
      k++;
    }
    if (k != 0) {
      facts.push_back({p, k});
    }
  }
  if (n > 1)
    facts.push_back({n, 1});
  return facts;
}

void solve() {
  int s,f,m;
  cin >> s >> f >> m;
  int ans = 1;
  for (int i=1;i<=m;i++){
    auto fr = factorize(i);
    auto cnt = [&](int n, int p) {
      ll res = 0;
      while (n > 1) {
        res += n/p;
        n/=p;
      }
      return res;
    };
    bool yes = true;
    for (auto [p, k] : fr) {
      ll a = cnt(s+f,p)-cnt(s,p), b = cnt(f,p);
      if (a-b < k) {
        yes = false;
      }
    }
    if (yes) {
      ans = i;
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  const int N = 1e5;
  sieves(N);
  solve();
}
