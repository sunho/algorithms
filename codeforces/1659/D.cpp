#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  vector<int> B(n);
  for(int i=0;i<n;i++) {
    cin >> B[i];
  }
  vector<int> A(n, 1);
  if (B[0] == 0) {
    A[0] = 0;
  }
  for(int i=0;i<n;i++) {
    if (A[i] == 0) {
      int j = i + B[i];
      if (j < n) {
        A[j]=0;
      }
    } else {
      if (B[i] == 0) {
        A[i] = 0;
      } else {
        int j = B[i];
        if (j < n) {
          A[j]=0;
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    cout << A[i] << " ";
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
