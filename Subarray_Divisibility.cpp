#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  vector<ll> pf(n+1);
  map<ll, int> cnt;
  for (int i=0;i<n;i++){
    pf[i+1] = pf[i] + A[i];
  }
  for (int i=0;i<=n;i++){
    cnt[(pf[i]%n+n)%n]++;
  }
  ll ans = 0;
  for (int i=0;i<=n;i++){
    cnt[(pf[i]%n+n)%n]--;
    ans += cnt[(pf[i]%n+n)%n];
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
