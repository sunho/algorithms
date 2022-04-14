#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  array<ll, 3> A;
  ll m;
  cin >> A[0] >> A[1] >> A[2] >> m;
  if (A[2]+A[1]+A[0] - 3 < m) {
    cout << "NO" << "\n";
    return;
  }
  sort(all(A));
  A[2]-=A[1];
  A[2]-=A[0];
  if (A[2] <= m + 1) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
