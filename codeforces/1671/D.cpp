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
  const ll inf = 1e18;
  int n,x;
  cin >> n >> x;
  vector<ll> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  ll ans = 0;
  for(int i=0;i<n-1;i++){
    ans += abs(A[i]-A[i+1]);
  }
  ll cand = inf;
  auto go = [&](int x) {
    ll m0 = inf;
    int idx;
    int n = A.size();
    for(int i=0;i<n;i++) {
      if (i == 0) {
        if (ckmin(m0, abs(x - A[i]))) idx = 0;
      }
      if (i == n-1) {
        if (ckmin(m0, abs(x - A[i]))) idx = n;
      }
      if (i != n-1) {
        if ((A[i] <= x && x <= A[i+1]) || (A[i+1] <= x && x <= A[i])) {
          m0 = 0;
        }
        if (ckmin(m0, min(abs(x - A[i]), abs(x - A[i+1]))*2)) idx = i+1;
      }
    }
    return make_pair(m0,idx);
  };
  auto [c,_] = go(1);
  cand = c;
  if (x != 1) {
    auto [c, idx] = go(1);
    auto [c2, _1] = go(x);
    cand = c+c2;
    if (A[0] >= x) {
      ckmin(cand, A[0] - 1);
    }
    if (A[n-1] >= x) {
      ckmin(cand, A[n-1] - 1);
    }
    A.insert(A.begin()+idx, 1);
    auto [c3, _2] = go(x);
    ckmin(cand, c+c3);
  }

  cout << ans + cand << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--){
    solve();
  }

  return 0;
}
