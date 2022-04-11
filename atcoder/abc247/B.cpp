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
  int n;
  cin >> n;
  vector<vector<string>> A(n, vector<string>(2));
  multiset<string> S;
  bool ok = true;
  for(int i=0;i<n;i++) {
    cin >> A[i][0] >> A[i][1];
    S.insert(A[i][0]);
    S.insert(A[i][1]);
    //if (A[i][0] == A[i][1]) ok = false;
  }
  for(int i=0;i<n;i++) {
    S.erase(S.lower_bound(A[i][0]));
    S.erase(S.lower_bound(A[i][1]));
    if (S.find(A[i][0]) != S.end() && S.find(A[i][1]) != S.end()) {
      ok = false;
    }
    S.insert(A[i][0]);
    S.insert(A[i][1]);
  }
  if (ok) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
