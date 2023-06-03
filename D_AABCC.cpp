#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
  const int N = 1e6;
  vector<ll> lp, pr;
  sieves(N, lp, pr);
  ll m;
  cin >> m;
  const int n = pr.size();
  int ans = 0;
  for (int i=0;i<n;i++){
    if (pr[i]*pr[i] > m) break;
    for (int j=i+1;j<n;j++){
      if (pr[i]*pr[i]*pr[j] > m) break;
      for (int k=j+1;k<n;k++){
        if (pr[i]*pr[i]*pr[j]*pr[k] > m) break;
        if (pr[i]*pr[i]*pr[j]*pr[k]*pr[k] > m) break;
        ans++;
      }
    }
  }
  cout << ans << "\n";
}
