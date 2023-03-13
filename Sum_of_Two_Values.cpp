#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, x;
  cin >> n >> x;
  vector A(n, 0);
  for(int i=0;i<n;i++) cin >> A[i];
  vector id(n, 0);
  iota(begin(id), end(id), 0);
  sort(begin(id), end(id), [&](int i, int j) { return A[i] < A[j]; });
  sort(begin(A), end(A));
  for (int i=0;i<n;i++){
    int a = A[i];
    int t = x-a;
    if (t<=0) continue;
    int j = lower_bound(begin(A)+i+1,end(A), t)-begin(A);
    if (j == n) continue;
    if (A[j] == t) {
      cout << id[i] + 1 << " " << id[j] + 1 << "\n";
      return;
    }
  }
  cout << "IMPOSSIBLE" << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
