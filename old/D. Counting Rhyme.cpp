
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void sieves(int PN, vector<int>& mobius, vector<ll>& pr) {
  vector<bool> comp(PN+1);
  mobius.assign(PN+1,0);
  mobius[1] = 1;
  for (int i=2; i <= PN; ++i) {
    if (!comp[i]) {
      pr.push_back(i);
      mobius[i] = -1;
    }
    for (int j=0; j < pr.size() && i*pr[j] <= PN; ++j) {
      comp[i*pr[j]] = true;
      if (i % pr[j] == 0) {
        break;
      }
      mobius[i*pr[j]] = mobius[i]*mobius[pr[j]];
    }
  }
}

// [gcd(x,y)=1] -> sum_d|gcd(x,y) mobis(d)
void generate_mobius(int PN, vector<int>& mobius, vector<ll>& pr) {
  vector<bool> comp(PN+1);
  mobius.assign(PN+1,0);
  mobius[1] = 1;
  for (int i=2; i <= PN; ++i) {
    if (!comp[i]) {
      pr.push_back(i);
      mobius[i] = -1;
    }
    for (int j=0; j < pr.size() && i*pr[j] <= PN; ++j) {
      comp[i*pr[j]] = true;
      if (i % pr[j] == 0) {
        break;
      }
      mobius[i*pr[j]] = mobius[i]*mobius[pr[j]];
    }
  }
}

vector<ll> gcd_convolution(vector<ll> p, vector<ll> a, vector<ll> b) {
  int n = a.size() - 1;
  for (int i=0; i < p.size() && p[i]<=n; ++i) {
    for (int j=n/p[i]; j>=1; --j) {
      a[j] += a[j * p[i]];	
      b[j] += b[j * p[i]];
    }
  }
  vector<ll> d(n+1);
  for (int i=1; i<=n; ++i) d[i] = a[i] * b[i];
  for (int i=0; i < p.size() && p[i]<=n; ++i) {
    for (int j=1; j * p[i] <= n; ++j) {
      d[j] -= d[j * p[i]];
    }
  }
  return d;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  const int N = 1e6;
  vector<int> mobius;
  vector<ll> pr;
  sieves(N+1, mobius, pr);
  while (t--) {
    int n;
    cin >> n;
    vector<ll> cnt(n+1);
    vector<int> A(n);
    for (int i=0;i<n;i++){
      cin >> A[i];
      cnt[A[i]] ++;
    }
    sort(begin(A),end(A));
    A.resize(unique(begin(A),end(A))-begin(A));
    vector<int> div(n+1);
    for (int i=0;i<A.size();i++){
      for (int j=A[i];j<=n;j+=A[i]) {
        div[j] = 1;
      }
    }
    auto res = gcd_convolution(pr, cnt, cnt);
    ll ans = 0;
    for (int d=1;d<=n;d++){
      if (div[d]) {
        ans += res[d];
      }
    }
    cout << ((ll)n*n - ans)/2 << "\n";
  }
}
