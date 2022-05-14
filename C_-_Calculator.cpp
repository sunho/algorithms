#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  const int N = 86;
  vector<ll> F(N+1);
  F[0] = 1;
  F[1] = 1;
  for(int i=2;i<=N;i++){
    F[i] = F[i-1]+F[i-2];
  }
  ll n;
  cin >> n;
  set<int> added;
  for(int i=N;i>=1;i--){
    if (F[i] <= n) {
      n -= F[i];
      added.insert(i);
    }
  }
  vector<int> ans;
  for(int i=0;i<=N;i++){
    if (added.count(N-i)) {
      if (i&1) {
        ans.push_back(2);
      } else {
        ans.push_back(1);
      }
    }
    if (i&1) {
      ans.push_back(3);
    } else {
      ans.push_back(4);
    }
  }
  cout << ans.size() << "\n";
  for(int x : ans) cout << x << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
