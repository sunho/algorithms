#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  map<int,int> cnt;
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    cnt[a]++;
  }
  int x = 0;
  int c=1;
  while (cnt[x]) {
    if (cnt[x] == 1) {
      if (!c) 
        break;
      c=0;
    }
    x++;
  }
  cout << x << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
