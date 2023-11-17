#include <bits/stdc++.h>

using namespace std;

int query(int l, int r) {
  if (l == r) return 0;
  cout << "? " << l+1 << " " << r+1 << endl;
  int inv;
  cin >> inv;
  return inv;
}

void solve() {
  auto f = [&](auto&& self, int l, int r) {
    if (l == r) {
      return l;
    }
    int m = (l+r)/2;
    int resl = self(self, l,m), resr = self(self, m+1,r);
    int bf = query(l,resr-1), af = query(l,resr);
    if (bf == af) {
      return resr;
    } else {
      return resl;
    }
  };
  int n;
  cin >> n;
  int ans = f(f, 0, n-1) + 1;
  cout << "! " << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
