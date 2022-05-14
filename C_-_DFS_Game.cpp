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
  vector<vector<int>> g(n);
  for(int i=1;i<n;i++){
    int p;
    cin >> p;
    --p;
    g[p].push_back(i);
  }
  vector<int> trav_num(n);
  auto calc_trav = [&](int u, auto&& self) -> int {
    int tot = 1;
    for(int v : g[u]) {
      tot += self(v, self);
    }
    trav_num[u] = tot;
    return tot;
  };
  calc_trav(0,calc_trav);
  auto dfs = [&](int u, auto&& self) -> pair<int,int> {
    pair<int,int> res = {1,0};
    vector<tuple<int, int, int>> cands;
    for(int v : g[u]) {
      auto cand = self(v, self);
      cands.push_back({(trav_num[v]%2==0),cand.first, cand.second});
    }
    vector<tuple<int, int, int>> rem;
    for (int i=0;i<(int)cands.size();i++){
      auto [k,x,y] = cands[i];
      if (k == 1 && x < y) {
        res.first += x;
        res.second += y;
      } else {
        rem.push_back({k,x,y});
      }
    }
    sort(all(rem), [](auto a, auto b) {
      auto [k,x,y] = a;
      auto [k2,x2,y2] = b;
      if (k == k2) {
        return y-x > y2-x2;
      }
      return k < k2;
    });
    int turn = 0;
    for(int i=0;i<(int)rem.size();i++){
      auto [k,x,y] = rem[i];
      if (turn == 0) {
        res.first += x;
        res.second += y;
      } else {
        res.first += y;
        res.second += x;
      }
      if (k == 0) {
        turn ^= 1;
      }
    }
    return res;
  };
  auto [x,y] = dfs(0, dfs);
  cout << x << "\n";
}
  
int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  
  solve();
  
  return 0;
}