#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int s,x,y;
  cin >> s >> x >> y;
  const int inf = 1e9;
  tuple<int,int,int> ans = {inf,0,0};
  for (int i=0;i<=s;i++){
    ll rem = s - (ll)x*i;
    if (rem >= 0 && rem % y == 0) {
      ans = min(ans, {i + rem/y, i, rem/y});
    }
  }
  auto [a,b,c] = ans;
  if (a == inf) {
    cout << "Impossible" << "\n";
  } else {
    cout << b << " " << c << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
