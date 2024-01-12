#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  array<ll,3> cur = {1, -1, 1};
  for (int i=0;i<n-1;i++){
    auto [a,b,c] = cur;
    array<ll, 3> nxt = cur;
    nxt[2] -= 2*a;
    nxt[2] += 2*b;
    nxt[0] += c;
    nxt[1] -= c;
    cur = nxt;
  }
  cout << cur[0] + cur[1] + cur[2] << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
