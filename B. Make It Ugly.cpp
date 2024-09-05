#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int g (int n) {
    return n ^ (n >> 1);
}

void solve() {
  for (int i=0;i<(1<<5);i++){
    cout << bitset<5>(g(i)) << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
