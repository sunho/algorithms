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
  int n;
  cin >> n;
  const int N = 2e5;
  vector<ll> S(N+1);
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    S[a]++;
  }
  ll ans = 0;
  for (int i=1;i<=N;i++) {
    for (int j=1;j*i<=N;j++){
      ans += S[i]*S[j]*S[i*j];
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
