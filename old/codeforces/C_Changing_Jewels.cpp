#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,x,y;
  cin >> n >> x >> y;
  auto dfs = [&](auto self, bool red, int n) -> ll {
    if (n == 1) {
      if (!red) return n;
      else return 0;
    }
    ll res = 0;
    if (red) {
      res += x*(self(self, false, n));
      res += self(self, true, n-1);
      
    } else {
      res += y*(self(self, false, n-1));
      res += self(self, true, n-1);
    }
    return res;
  };
  cout << dfs(dfs, true, n);
}
