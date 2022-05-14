#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

// sieves + lp
// works when N <= 10^7
// O(n log n) time
void sieves(int PN, vector<int>& lp, vector<int>& pr) {
  lp.assign(PN+1,0);
  for (int i=2; i <= PN; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j=0; j < (int)pr.size() && pr[j] <= lp[i] && (ll)i*pr[j] <= PN; ++j) {
      lp[i * pr[j]] = pr[j];
    }
  }
}

void solve() {
  const int N = 1e6;
  vector<int> lp, pr;
  sieves(N, lp, pr);
  int l,r;
  cin >> l >> r;
  vector<int> factors;
  ll ans = 0;
  for(int n=max(l,2);n<=r;n++){
    int nn = n;
    while (nn != 1) {
      int p = lp[nn];
      while (nn % p == 0) {
        nn /= p;
      }
      factors.push_back(p);
    }
    int m = (int)factors.size();
    ll c = 0;
    for(int mask = 1; mask < (1<<m); mask++) {
      int pcnt = 0;
      int fact = 1;
      for(int j=0;j<m;j++){
        if (mask >> j & 1) {
          fact *= factors[j];
          pcnt++;
        }
      }
      ll cand = r / fact - (n-1) / fact;
      if (pcnt&1) {
        c += cand;
      } else {
        c -= cand;
      }
    }
    c -= r/n;
    ans += c;
    factors.clear();
  }
  cout << ans*2 << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
