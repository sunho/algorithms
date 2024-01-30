#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int a,b,c,x;
  cin >> a >> b >> c >> x;
  array<int,3> r = {a%x,b%x,c%x};
  sort(begin(r),end(r));
  if (r[0] == 0 && r[1] == 0)  {
    cout << 1 << "\n";
  } else {
    cout << 0 << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
