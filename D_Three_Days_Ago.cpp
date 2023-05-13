#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string s;
  cin >> s;
  int n = s.size();
  vector<ll> A(n);
  for (int i=0;i<n;i++){
    A[i] = 1ll << (s[i]-'0');
  }
  vector<ll> pf(n+1);
  for (int i=0;i<n;i++){
    pf[i+1] = pf[i] ^ A[i];
  }
  ll ans = 0;
  map<ll, int> cnt;
  for (int i=0;i<=n;i++){
    cnt[pf[i]]++;
  }
  for (int i=0;i<n;i++){
    cnt[pf[i]]--;
    ans += cnt[pf[i]];
  }
  cout << ans << "\n";
}
