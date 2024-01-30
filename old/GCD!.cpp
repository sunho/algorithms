#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// factor one number count p^k
// O(sqrt(n))
vector<pair<ll,int>> factorize(ll n) {
  vector<pair<ll,int>> facts;
  for (ll d = 2; d * d <= n; d++) {
    int k=0;
    while (n % d == 0) {
      n /= d;
      k++;
    }
    if (k != 0) {
      facts.push_back({d,k});
    }
  }
  if (n > 1)
    facts.push_back({n,1});
  return facts;
}

void solve(int n, int k) {
  auto fs = factorize(k);
  auto cnt = [&](ll p) {
    int res = 0;
    int pp = p;
    for (ll pp=p;pp<=n;pp*=p){
      res+=n/pp;
    }
    return res;
  };
  int ans = 1;
  for (auto [p, c] : fs) {
    int k = min(cnt(p),c);
    for (int i=0;i<k;i++){
      ans *= p;
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,k;
  while (cin >> n >> k) {
    solve(n,k);
  }
}
