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
  ll ans = 0;
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  for(int i=0;i<n;i++) cin >> A[i];
  for(int i=0;i<n;i++) cin >> B[i];
  for(int i=0;i<n-1;i++){
    ans += min(abs(A[i] - B[i+1]) + abs(B[i] - A[i+1]), abs(A[i] - A[i+1]) + abs(B[i] - B[i+1]));
  }
  cout << ans << "\n";
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
