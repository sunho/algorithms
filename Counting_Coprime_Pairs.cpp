#include <bits/stdc++.h>
using namespace std;
using ll = long long;




int main() {
  int n;
  cin >> n;

  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(begin(A),end(A));

  const int PN = 1e6;
  ll ans = 0;
  vector<int> cnt(PN+1);
  vector<int> factors;
  for (int i=0;i<n;i++){
    int m = A[i];
    while (m != 1) {
      int p = lp[m];
      factors.push_back(p);
      while (m % p == 0) {
        m /= p;
      }
    }
    for (int mask=1;mask<(1<<factors.size());mask++){
      int cur = 1;
      int mcnt = 0;
      for (int k=0;k<factors.size();k++){
        if (mask & (1 << k)) {
          cur *= factors[k];
          mcnt++;
        }
      }
      if (mcnt % 2)
        ans += cnt[cur];
      else
        ans -= cnt[cur];
    }
    for (int mask=1;mask<(1<<factors.size());mask++){
      int cur = 1;
      for (int k=0;k<factors.size();k++){
        if (mask & (1 << k)) {
          cur *= factors[k];
        }
      }
      cnt[cur]++;
    }
    factors.clear();
  }
  cout << (ll)(n)*(n-1)/2 - ans << "\n";
}
