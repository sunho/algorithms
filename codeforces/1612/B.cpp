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
  int a,b;
  cin >> a >> b;
  vector<vector<int>> S(2);
  set<int> C;
  for(int i=1;i<=n;i++) C.insert(i);
  S[0].push_back(a);
  S[1].push_back(b);
  C.erase(a);
  C.erase(b);
  n-=2;
  for(int i=0;i<n/2;i++) {
    auto it = C.upper_bound(b);
    if (it == C.end() || a > *it) {
      it = --C.end();
    }
    if (a > *it) {
      cout << "-1" << "\n";
      return;
    }
    S[0].push_back(*it);
    C.erase(it);
  }
  for(int i=0;i<n/2;i++) {
    auto it = C.lower_bound(a);
    if (it != C.begin()) {
      it--;
    }
    if (b < *it) {
      it = C.begin();
    }
    if (b < *it) {
      cout << "-1" << "\n";
      return;
    }
    S[1].push_back(*it);
    C.erase(it);
  }
  for(int i=0;i<2;i++) {
    for (auto x : S[i]) cout << x << " ";
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
