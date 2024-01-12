#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  ll s;
  cin >> s;
  if (s < (ll)n * (n - 1) / 2) {
    cout << -1 << "\n";
    return;
  }
  s -= (ll)n * (n - 1) / 2;
  vector<int> edges(n - 1);
  ll cur = min((ll)m, (ll)(n - 2) * (n - 1) / 2 + 1);
  iota(begin(edges), end(edges), 1);
  for (int i = n - 2; i >= 0; i--) {
    cur = min(cur, (ll)i * (i + 1) / 2 + 1);
    while (s < cur - i - 1 && cur > i + 1) {
      cur--;
    }
    s -= cur - i - 1;
    edges[i] = cur;
    cur--;
  }
  if (s != 0) {
    cout << -1 << "\n";
    return;
  }
  cur = 1;
  int sub = 1;
  int ptr = 0;
  for (int i = 0; i < n - 1; i++) {
    while (edges[i] > cur) {
      cout << ptr + 1 << " " << sub + 2 << "\n";
      ptr++;
      if (ptr == sub) {
        ptr = 0;
        sub++;
      }
      cur++;
    }
    cur++;
    cout << i + 1 << " " << i + 2 << "\n";
  }
  while (cur <= m) {
    cout << ptr + 1 << " " << sub + 2 << "\n";
    ptr++;
    if (ptr == sub) {
      ptr = 0;
      sub++;
    }
    cur++;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
