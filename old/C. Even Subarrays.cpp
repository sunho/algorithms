#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<ll> lp;
vector<ll> pr;
// sieves + lp
// works when N <= 10^7
// O(n log n) time
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

vector<int> cands;

void solve() {
  int n;
  cin >> n;
  int lg = ceil(log2(n))+1;
  vector<int> A(n);
  const int N = 1<<lg;
  vector<int> pf(n+1);
  for (int i=0;i<n;i++){
    cin >> A[i];
    pf[i+1] ^= A[i];
  }
  for (int i=0;i<n;i++){
    pf[i+1]^=pf[i];
  }
  vector<int> cnt(N);
  ll ans = 0;
  for (int i=0;i<n;i++){
    cnt[pf[i]]++;
    for (int x : cands) {
      if (x >= N) break;
      ans += (ll)cnt[x^pf[i+1]];
    }
  }
  cout << (ll)n*(n+1)/2-ans << "\n";
}

int main() {
  const int N = 1<<18;
  sieves(N);
  cands.push_back(0);
  for (int i=1;i<=N;i++){
    auto x = factorize(i);
    bool even = false;
    for (auto [_,c] : x) {
      if (c%2 == 1) {
        even = true;
      }
    }
    if (!even) {
      cands.push_back(i);
    }
  }

  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
