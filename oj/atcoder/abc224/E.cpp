#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,m,k;
  cin >> n >> m >> k;
  map<int, vector<tuple<int,int,int>>> pts;
  for(int i=0;i<k;i++) {
    int a,b,w;
    cin >> a >> b >> w;
    --a,--b;
    pts[w].push_back({a,b,i});
  }
  vector<int> ans(k);
  vector<int> dpY(n,-1);
  vector<int> dpX(m,-1);
  for (auto it = pts.rbegin(); it != pts.rend(); ++it) {
    int w = it->first;
    map<int, int> nextY;
    map<int, int> nextX;
    for (auto [i,j, id] : it->second) {
      int d = max(dpY[i] + 1, dpX[j] + 1);
      ans[id] = d;
      nextY[i] = max(nextY[i], d);
      nextX[j] = max(nextX[j], d);
    }
    for (auto [i, d] : nextY) {
      dpY[i] = d;
    }
    for (auto [i, d] : nextX) {
      dpX[i] = d;
    }
  }
  for(int i=0;i<k;i++){
    cout << ans[i] << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
