#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  pair<int,int> ans = {1e9,1e9};
  for (int i=0;i<n;i++){
    int x,y;
    cin >> x >> y;
    ans = min(ans, {y,x});
  }
  cout << ans.second << " " << ans.first << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
