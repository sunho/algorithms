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

void solve() {
  ll a, b;
  cin >> a >> b;
  auto f = [&](ll x) {
    ll res = 0;
    for (ll p : pr) {
      for (__int128_t pp = p * p; pp <= x; pp *= p)  {
        res++;
      }
    }
    return res;
  };
  cout << f(b) - f(a-1);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  const int N = 1e7;
  sieves(N);
  solve();
}
