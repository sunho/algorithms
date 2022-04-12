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
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i=0;i<n;i++) {
    int c;
    cin >> a[i];
    // int b = 1;
    // for(int i=0;i<c;i++){
    //   b *= 10;
    // }
    // a[i] = b;
  }
  auto pow10 = [&](int n) {
    ll res = 1;
    while (n--) {
      res *= 10;
    }
    return res;
  };
  k++;
  ll ans = 0;
  for(int i=0;i<n;i++) {
    if (i != n-1) {
      int c = a[i+1] - a[i];
      int maxi = pow10(c) - 1;
      int d = min(maxi, k);
      ans += d * pow10(a[i]);
      k-=d;
    } else {
      ans += pow10(a[i]) * k;
    }
  }
  cout << ans << "\n";
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
