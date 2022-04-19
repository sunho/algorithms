#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define _0 first
#define _1 second
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(all(A));
  for(int i=n-1;i>=0;i--){
    if (i == 0) {
      m -= (A[n-1]+1);
    } else {
      m -= (A[i]+1);
    }
    if (m < 0) {
      cout << "NO" << "\n";
      return;
    }
  }
  cout << "YES" << "\n";
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
