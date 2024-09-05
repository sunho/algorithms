#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  map<int,int> cnt1, cnt2;
  for (int i=1;i<=n;i++){
    cnt2[i] = 2;
  }
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    cnt2[a] --;
    cnt1[a] ++;
  }
  int s = 0;
  for (int i=1;i<=n;i++){
    if (cnt1[i] == 2) {
      s++;
    }
  }
  cout << s << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
