#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> able(2, vector<int>(2));
  for (int i=0;i<n;i++){
    int x,y;
    cin >> x >> y;
    if (x < 0) able[0][0] = true;
    if (x > 0) able[0][1] = true;
    if (y < 0) able[1][0] = true;
    if (y > 0) able[1][1] = true;
  }
  int cnt = 0;
  for (int i=0;i<2;i++) for (int j=0;j<2;j++) cnt += able[i][j];
  if (cnt == 4) {
    cout << "NO" << "\n";
  } else {
    cout << "YES" << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
