#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  while (n--) {
    int x,y;
    cin >> x >> y;
    --x,--y;
    int level = max(x,y)+1;
    ll start = (ll)(level-1) * (level-1) + 1;
    if (level % 2) {
      cout << start + y + (level - x - 1) << "\n";
    } else {
      cout << start + (level - y - 1) + x << "\n";
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
