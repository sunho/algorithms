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
  ll a,b,x;
  cin >> a >> b >> x;
  bool ok = false;
  map<pair<ll,ll>,bool> memo;
  auto check = [&](ll a, ll b, auto&& self) -> bool{
    if (memo.count({a,b})) {
      return memo[{a,b}];
    }
    if (a == x || b == x) {
      return true;
    }
    if (a <= 0 || b <= 0) {
      return false;
    }
    if (a < x && b < x) {
      return false;
    }
    if (a < b) swap(a,b);
    bool res = false;
    ll cnt = (a-x)/b;
    if (cnt != 0) {
      res |= self(b,a-cnt*b,self);
    }
    ll cnt2 = (a-b+b-1)/b;
    if (cnt2 != 0) {
      res |= self(b,abs(a-cnt2*b),self);
    }
    memo[{a,b}] = res;
    return res;
   
  };
  if (check(a,b,check)) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }

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
