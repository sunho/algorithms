#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,k;
  cin >> n >> k;
  vector<int> A(n);
  for(int i=0;i<n;i++) {
    char c;
    cin >> c;
    A[i] = c-'0';
  }
  if (k == 0) {
    for(int i=0;i<n;i++) {
      cout << A[i];
    }
    cout << "\n";
    for(int i=0;i<n;i++) {
      cout << 0 << " ";
    }
    cout << "\n";
    return;
  }
  int kk = k;
  vector<int> ans(n);
  for(int i=0;i<n-1;i++) {
    if (kk%2 == 1) {
      if (A[i] == 1) {
        if (k != 0) {
          A[i] = 0;
          ans[i] = 1;
          k--;
        }
      }
    } else {
      if (A[i] == 0) {
        if (k != 0) {
          A[i] = 1;
          ans[i] = 1;
          k--;
        }
      }
    }
  }
  ans[n-1] = k;
  if (k%2 == 1) {
    A[n-1]^=1;
  }
  if (kk % 2 == 1) {
    for(int i=0;i<n;i++) {
     A[i]^=1;
    }
  }
  for(int i=0;i<n;i++) {
    cout << A[i];
  }
  cout << "\n";
  for(int i=0;i<n;i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
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
