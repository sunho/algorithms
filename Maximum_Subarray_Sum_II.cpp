#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<ll> pf(n+1);
  for (int i=0;i<n;i++){
    pf[i+1] = pf[i] + A[i];
  }
  multiset<ll> S;
  for (int i=a;i<=b;i++) {
    S.insert(pf[i]);
  }
  ll inf = 1e18;
  ll ans = -inf;
  for (int i=0;i<n-a+1;i++){
    ans = max(ans, *--S.end() - pf[i]);
    S.erase(S.find(pf[i+a]));
    if (i+b+1<=n) {
      S.insert(pf[i+b+1]);
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
