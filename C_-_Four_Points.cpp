#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  vector<pair<int,int>> v;
  set<pair<int,int>> s;
  const int inf = 1e9;
  pair<int,int> mini, maxi;
  mini = {inf,inf};
  maxi = {-inf,-inf};
  for(int i=0;i<3;i++){
    int a,b;
    cin >> a >> b;
    v.push_back({a,b});
    s.insert({a,b});
    mini.first = min(mini.first, a);
    mini.second = min(mini.second,b);
    maxi.first = max(maxi.first, a);
    maxi.second = max(maxi.second, b);
  }
  array<pair<int,int>,4> cands = {{{mini.first, mini.second}, {mini.first, maxi.second}, {maxi.first, mini.second}, {maxi.first, maxi.second}}};
  for (auto cand : cands) {
    if (s.count(cand)) continue;
    cout << cand.first << " " << cand.second << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
