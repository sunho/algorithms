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
  vector<ll> A(n);
  ll sum = 0;
  for(int i=0;i<n;i++){
    cin >> A[i];
    sum += A[i];
  }
  sort(all(A));
  int m;
  cin >> m;
  for(int i=0;i<m;i++){
    ll x, y;
    cin >> x >> y;
    ll def = sum;
    ll gans = 1e18;
    int j = lower_bound(all(A), x)-A.begin();
    if (j == n) {
      ll ans = 0;
      def -= A[n-1];
      ans += x - A[n-1];
      ans += max(y-def,0ll);
      gans = ans;
    } else {
      gans = min(gans, max(y-(def-A[j]),0ll));
      if (j!=0) {
        gans = min(gans, max(y-(def-A[j-1]),0ll) + (x-A[j-1]));
      }
    }
    cout << gans << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
