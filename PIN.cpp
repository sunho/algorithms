#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,d;
  cin >> n >> d;
  unordered_map<string, ll> cnt;
  vector<ll> cnt2(1<<4);
  for (int i=0;i<n;i++){
    string s;
    cin >> s;
    for (int msk=0;msk<(1<<4);msk++){
      auto t=s;
      for (int j=0;j<4;j++){
        if (!((msk >> j)&1)) {
          t[j] = '$';
        }
      }
      cnt2[msk] += cnt[t];
      cnt[t]++;
    }
  }
  vector<ll> f(6);
  auto choose = [](int n, int k) {
    ll res = 1;
    for (int i=1;i<=n;i++) res *= i;
    for (int i=1;i<=n-k;i++) res /= i;
    for (int i=1;i<=k;i++) res /= i;
    return res;
  };
  d = 4-d;
  ll ans = 0;
  int neg = 1;
  for (int i=d;i<=4;i++) {
    ll sum = 0;
    for (int msk=0;msk<(1<<4);msk++){
      if (__builtin_popcount(msk) == i) {
        sum += cnt2[msk];
      }
    }
    ans += neg * sum * choose(i, d);
    neg *= -1;
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
