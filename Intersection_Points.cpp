#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using indexed_set = tree<T,null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<tuple<int, int,int>> hori, vert;
  for (int i=0;i<n;i++){
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      vert.push_back({x1, y1,y2});
    }
    if (y1 == y2) {
      hori.push_back({y1, x1,x2});
    }
  }
  vector<pair<int,int>> yin;
  vector<pair<int,int>> yout;
  for (int i=0;i<vert.size();i++) {
    auto [x,y1,y2] = vert[i];
    yin.push_back({y1+1,i});
    yout.push_back({y2,i});
  }
  sort(begin(yin), end(yin));
  sort(begin(yout), end(yout));
  sort(begin(hori), end(hori));

  int cur_in=0, cur_out=0;
  ll ans = 0;
  indexed_set<pair<int,int>> cnt;
  for (auto [y, x1, x2] : hori) {
    while (cur_in != yin.size() && yin[cur_in].first <= y) {
      int j = yin[cur_in].second;
      cnt.insert({get<0>(vert[j]), j});
      cur_in++;
    }
    while (cur_out != yout.size() && yout[cur_out].first <= y) {
      int j = yout[cur_out].second;
      cnt.erase({get<0>(vert[j]), j});
      cur_out++;
    }
    int res = cnt.order_of_key({x2-1,n}) - cnt.order_of_key({x1+1,0});
    ans += res;
  }
  cout << ans << "\n";
}
