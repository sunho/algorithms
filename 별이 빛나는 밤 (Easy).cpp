#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<tuple<int, int, int>> A(n);
  for (int i = 0; i < n; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    A[i] = {x, y, w};
  }
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int N = x2 - x1 + 1;
  int M = y2 - y1 + 1;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    int x = i + x1;
    vector<ll> imos2(M + 1);
    vector<ll> imos(M + 1);
    for (int j = 4; j < 5; j++) {
      auto [u, v, w] = A[j];
      w -= abs(u - x);
      w--;
      if (w < 0)
        continue;
      int beg = v - w;
      if (beg > y2)
        continue;
      int diff = y1 - beg;
      if (diff > 0 && diff <= w) {
        imos[0] += diff;
      }
      if (v >= y1) {
        imos2[max(v - w - y1, 0)]++;
        // imos2[min(v - y1, M)]--;
      }
      if (v >= y1 && v <= y2) {
        imos2[min(v - y1, M)]--;
        imos2[min(v - y1 + w + 1, M)]++;
      }
    }
    for (int j = 0; j < M; j++) {
      imos2[j + 1] += imos2[j];
    }
    for (int j = 0; j <= M; j++) {
      imos[j] += imos2[j];
    }
    for (int j = 0; j < M; j++) {
      imos[j + 1] += imos[j];
    }
    for (int j = 0; j < M; j++) {
      cout << imos[j] << " ";
      ans += imos[j];
    }
    cout << "\n";
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
