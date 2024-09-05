#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifndef ONLINE_JUDGE
#include "lib/debug.h"
#define dbg(...) std::cerr << __DEBUG_UTIL__::outer << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

void solve() {
  int n;
  ll T;
  cin >> n >> T;
  string s;
  cin >> s;
  vector<int> A(n);
  ll sum = 0;
  vector<int> cnt(26);
  for (int i=0;i<n;i++){
    A[i] = s[i] - 'a';
    sum += 1ll << A[i];
    cnt[A[i]]++;
  }
  cnt[A.back()]--;
  cnt[A[n-2]]--;
  sum -= 1ll << A.back();
  sum -= 1ll << A[n-2];
  dbg(sum);
  ll tgt = T + sum - (1ll<<A.back()) + (1ll<<A[n-2]);
  if (tgt < 0) {
    cout << "No" << "\n";
    return;
  }
  for (int z=25;z>=0;z--){
    dbg(tgt);
    ll k = tgt/(2ll<<z);
    k = min(k, (ll)cnt[z]);
    tgt -= k * (2ll << z);
  }
  if (tgt != 0) {
    cout << "No" << "\n";
  } else {
    cout << "Yes" << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
