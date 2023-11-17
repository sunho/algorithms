#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;
  const int N = 1024;
  vector<int> cnt(N);
  for (int i=0;i<n;i++){
    string s;
    cin >> s;
    int mask = 0;
    for (char c : s) {
      mask |= 1 << (c-'0');
    }
    cnt[mask]++;
  }
  ll ans = 0;
  for (int msk=1;msk<N;msk++){
    for (int nxt=1;nxt<N;nxt++){
      if (__builtin_popcount(msk | nxt) == k) {
        if (nxt == msk) {
          ans += (ll)cnt[msk]*(cnt[msk]-1);
        } else {
          ans += (ll)cnt[msk]*cnt[nxt];
        }
      }
    }
  }
  cout << ans/2 << "\n";
}
