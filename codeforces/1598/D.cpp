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
  ll n;
  cin >> n;
  vector<pair<int,int>> A(n);
  map<int,ll> cnt;
  map<int,ll> cnt_dif;
  for(int i=0;i<n;i++){
    cin >> A[i].x >> A[i].y;
    cnt[A[i].x]++;
    cnt_dif[A[i].y]++;
  }
  sort(all(A));
  ll ans = n*(n-1)*(n-2)/6;
  for(int i=0;i<n;i++){
    ans -= (cnt[A[i].x]-1)*(cnt_dif[A[i].y]-1);
  }
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
