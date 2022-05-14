#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  auto f = [&](int i, auto&& self) {
    list<int> res;
    if (i == 1) {
      res.push_back(1);
      return res;
    }
    auto l = self(i-1, self);
    res.insert(res.end(), all(l));
    res.insert(res.end(), i);
    res.insert(res.end(), all(l));
    return res;
  };
  auto ans = f(n, f);
  for(auto x : ans) {
    cout << x << " ";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
