#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Find lowest prime divisors and prime list in [1,PN]
void sieves(int PN, vector<ll>& lp, vector<ll>& pr) {
  lp.assign(PN+1,0);
  for (int i=2;i<=PN;i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j=0;j<pr.size()&&pr[j]<=lp[i]&&i*pr[j]<=PN;j++) {
      lp[i * pr[j]] = pr[j];
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<ll> lp, pr;
  sieves(1e6+10, lp, pr);

  int t;
  cin >> t;
  while (t--) {
    int n,m;
    cin >> n >> m;
    int nn = n;
    bool ok = false;
    while (nn != 1) {
      if (lp[nn] <= m) {
        ok = true;
      }
      nn /= lp[nn];
    }
    if (ok) {
      cout << "NO" << "\n";
    } else {
      cout << "YES" << "\n";
    }
  }
}
