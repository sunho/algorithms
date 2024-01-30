#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 1000000007; // 998244353
struct mint {
  int x;
  mint() : x(0) {}
  mint(ll val) : x(val % MOD) { x += (x < 0) * MOD; }
};
mint &operator+=(mint &a, mint b) {
  if ((a.x += b.x) >= MOD)
    a.x -= MOD;
  return a;
}
mint &operator-=(mint &a, mint b) {
  if ((a.x -= b.x) < 0)
    a.x += MOD;
  return a;
}
mint operator*(mint a, mint b) { return mint((ll)a.x * b.x); }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
bool operator<(mint a, mint b) { return a.x < b.x; }
mint &operator*=(mint &a, mint b) { return a = a * b; }
mint pow(mint a, ll p) {
  return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mint inv(mint a) { return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }

// sieves + lp
// works when N <= 10^7
// O(n) time
void sieves(int PN, vector<ll> &lp, vector<ll> &pr) {
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

vector<ll> lp, pr;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  const ll N = 1e18;
  sieves((int)1e7, lp, pr);
  priority_queue<pair<ll, mint>> pq;
  for (ll p : pr) {
    int cnt = 0;
    mint res = 1;
    for (__int128_t k = p; k <= N; k *= p) {
      if (cnt != 0)
        pq.push({-(ll)k, p});
      cnt++;
      res *= p;
    }
  }
  int t;
  cin >> t;
  vector<ll> Q(t);
  for (int i = 0; i < t; i++) {
    cin >> Q[i];
  }
  vector<int> id(t);
  iota(begin(id), end(id), 0);
  sort(begin(id), end(id), [&](int i, int j) { return Q[i] < Q[j]; });
  vector<mint> ans(t);
  mint cur = 1;
  for (int i = 0; i < t; i++) {
    int k = id[i];
    while (!pq.empty() && -pq.top().first <= Q[k]) {
      cur *= pq.top().second;
      pq.pop();
    }
    ans[k] = cur;
  }
  for (int i = 0; i < t; i++) {
    cout << "Case " << i + 1 << ": " << ans[i].x << "\n";
  }
}
