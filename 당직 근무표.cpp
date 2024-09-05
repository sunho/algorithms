#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  map<int,int> cnt;
  int mx = 0;
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    cnt[a]++;
    mx = max(mx,cnt[a]);
  }
  if (mx*2 <= n+1) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
