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
  for(int i=0;i<n;i++){
    A[i] *= n;
    A[i] -= sum;
  }
  queue<ll> S;
  map<ll, int> cnt;
  ll zeros = 0;
  for(int i=0;i<n;i++){
    if (A[i] > 0) {
      S.push(A[i]);
    }
    if (A[i] < 0) {
      cnt[A[i]]++;
    }
    if (A[i] == 0) {
      zeros++;
    }
  }
  ll ans = 0;
  while (!S.empty()) {
    ll x = S.front();
    S.pop();
    ans += cnt[-x];
  }
  ans += zeros*(zeros-1)/2;
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
