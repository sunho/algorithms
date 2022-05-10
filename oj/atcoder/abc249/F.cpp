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
  int n,k;
  cin >> n >> k;
  vector<pair<int,int>> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i]._0 >> A[i]._1;
  }
  ll ans = -1e18;
  ll cur = 0;
  multiset<int> q;
  for(int i=n-1;i>=0;i--){
    if (A[i]._0 == 1) {
      ans = max(ans, A[i]._1 + cur);
      k--;
      if (k < 0) break;
      while ((int)q.size() > k) {
        cur += *(--q.end());
        q.erase(--q.end());
      }
    } else {
      if (A[i]._1 < 0) {
        q.insert(A[i]._1);
      } else {
        cur += A[i]._1;
      }
      while ((int)q.size() > k) {
        cur += *(--q.end());
        q.erase(--q.end());
      }
    }
    if (i == 0) {
      ans = max(ans, cur);
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
