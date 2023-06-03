#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  map<int, pair<ll,ll>> cnt;
  auto get_cell = [&](int cur, int i, int j) {
    auto m = bitset<18>(cur);
    int k = i*3+j;
    if (m[k]) return 1;
    else if (m[k+9]) return -1;
    return 0;
  };
  auto set_cell = [&](int cur, int i, int j, int p) -> int {
    auto m = bitset<18>(cur);
    int k = i*3+j;
    if (p == 1) m[k] = 1;
    else m[k+9] = 1;
    return m.to_ulong();
  };
  auto determine_winner = [&](int cur) {
    for (int p : {-1,1}) {
      for (int i=0;i<3;i++){
        bool ok = true;
        for (int j=0;j<3;j++){
          if (get_cell(cur, i, j) != p) {
            ok = false;
          }
        }
        if (ok) return p;
        ok = true;
        for (int j=0;j<3;j++){
          if (get_cell(cur, j, i) != p) {
            ok = false;
          }
        }
        if (ok) return p;
      }
      bool ok = true;
      for (int i=0;i<3;i++){
        if (get_cell(cur, i, i) != p) {
          ok = false;
        }
      }
      if (ok) return p;
      ok = true;
      for (int i=0;i<3;i++){
        if (get_cell(cur, i, 2-i) != p) {
          ok = false;
        }
      }
      if (ok) return p;
    }
    return 0;
  };
  auto dfs = [&](auto self, int cur) -> void {
    int winner = determine_winner(cur);
    if (winner != 0) {
      if (winner == 1) {
        cnt[cur] = {0,1};
      } else {
        cnt[cur] = {1,0};
      }
      return;
    }
    int turn = __builtin_popcount(cur);
    if (turn == 9) {
      cnt[cur] = {0,0};
      return;
    }
    int p = (turn & 1) ? 1 : -1;
    pair<ll,ll> res;
    for (int i=0;i<3;i++){
      for (int j=0;j<3;j++){
        if (get_cell(cur,i,j) == 0) {
          int nxt = set_cell(cur,i,j,p);
          if (!cnt.count(nxt)) {
            self(self, nxt);
          }
          res.first += cnt[nxt].first;
          res.second += cnt[nxt].second;
        }
      }
    }
    cnt[cur] = res;
  };

  dfs(dfs, 0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int cur = 0;
    for (int i=0;i<9;i++){
      if (s[i] =='O') { cur |= (1<<i); }
      else if (s[i] == 'X') { cur |= (1<<(i+9)); }
    }
    if (!cnt.count(cur)) {
      cout << -1 << " " << -1 << "\n";
    } else {
      cout << cnt[cur].first << " " << cnt[cur].second << "\n";
    }
  }
}
