#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n + 1) {}
  void update(int v, int delta) {
    for (++v; v <= n; v += v & (-v))
      bits[v] += delta;
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r & (-r))
      res += bits[r];
    return res;
  }
  ll query(int l, int r) { return query(r) - query(l - 1); }
};

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> A(n);
  fenwick_tree ft(n);
  set<int> ones;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    ft.update(i, A[i]);
    if (A[i] == 1) {
      ones.insert(i);
    }
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int s;
      cin >> s;
      if (ones.empty()) {
        if (s % 2 == 1) {
          cout << "NO"
               << "\n";
        } else {
          if (s <= ft.query(0, n - 1)) {
            cout << "YES"
                 << "\n";
          } else {
            cout << "NO"
                 << "\n";
          }
        }
        continue;
      }
      int r = *--ones.end();
      int l = *ones.begin();
      int x = l;
      int y = n - 1 - r;
      int sum = ft.query(l, r);
      int mx = 0;
      if ((s & 1) == (sum & 1)) {
        mx = max(mx, sum + 2 * (x + y));
      } else {
        mx = max({mx, sum + 2 * x - 1, sum + 2 * y - 1});
      }
      if (s <= mx) {
        cout << "YES"
             << "\n";
      } else {
        cout << "NO"
             << "\n";
      }
    } else {
      int i, v;
      cin >> i >> v;
      --i;
      if (A[i] == 1) {
        ones.erase(i);
      }
      ft.update(i, v - A[i]);
      A[i] = v;
      if (A[i] == 1) {
        ones.insert(i);
      }
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
