#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(begin(A),end(A));
  const int inf = 1<<30;
  auto g = [&](auto&& self, int l1, int r1, int l2, int r2, int k) -> int {
    if (l1 == r1 || l2 == r2) {
      return inf;
    }
    if (k == -1) {
      return 0;
    }
    int m1 = l1, m2 = l2;
    while (m1 < r1 && (A[m1] >> k & 1) == 0) m1++;
    while (m2 < r2 && (A[m2] >> k & 1) == 0) m2++;
    if ((m1 < r1 && m2 < r2) || (l1 < m1 && l2 < m2))
      return min({self(self, l1, m1, l2, m2, k-1),self(self, m1, r1, m2, r2, k-1)});
    else 
      return min({self(self, l1, m1, m2, r2, k-1),self(self, m1, r1, l2, m2, k-1)}) + (1<<k);
  };
  auto f = [&](auto&& self, int l, int r, int k) -> ll {
    if (k == -1 || l == r) {
      return 0;
    }
    int m = l;
    while (m < r && (A[m] >> k & 1) == 0) m++;
    return self(self, l, m, k-1) + self(self, m, r, k-1) + ((l != m && m != r) ? g(g, l, m, m, r, 29) : 0);
  };
  cout << f(f,0,n,29) << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
