#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<tuple<int,int,int>> A;
  for (int i=0;i<n;i++){
    int l,r,c;
    cin >> c >> l >> r;
    A.push_back({l,r,c});
  }
  sort(begin(A),end(A),[&](auto a, auto b) {
    return get<1>(a) < get<1>(b);
  });
  vector<int> mt(n, -1);
  vector<set<pair<int,int>>> S(2);
  for (int i=0;i<n;i++){
    auto [l,r,c] = A[i];
    pair<int,int> opr = {-1,-1};
    while (!S[c^1].empty()) {
      auto it = --S[c^1].end();
      if (it->first < l) break;
      opr = max(opr, {it->first, it->second});
      int gid = it->second;
      if (mt[gid] != -1) {
        S[c].erase({get<1>(A[mt[gid]]), mt[gid]});
      }
      S[c^1].erase(it);
    }
    if (opr.first != -1) {
      S[c^1].insert(opr);
      mt[i] = opr.second;
      mt[opr.second] = i;
    }
    S[c].insert({r, i});
  }
  int cnt = 0;
  int ans = 0;
  for (auto& B : S) {
    for (auto [_, i] : B) {
      if (mt[i] == -1) {
        ans++;
      } else {
        cnt++;
      }
    }
  }
  ans += cnt/2;
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
