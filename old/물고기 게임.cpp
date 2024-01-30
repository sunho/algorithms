#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<vector<ll>> A(2, vector<ll>(n));
  ll sum = 0;
  for (int i=0;i<2;i++){
    for (int j=0;j<n;j++){
      cin >> A[i][j];
    }
  }
  if (n > 4) {
    if (n%2 == 0) {
      vector<vector<ll>> B(2, vector<ll>(4));
      for (int i=0;i<2;i++){
        for (int j=0;j<n;j++){
          if (j < n/2-1)  {
            B[i][0] += A[i][j];
          } else if (j == n/2-1) {
            B[i][1] += A[i][j];
          } else if (j == n/2)  {
            B[i][2] += A[i][j];
          } else {
            B[i][3]+=A[i][j];
          }
        }
      }
      A = B;
      n = 4;
    } else {
      vector<vector<ll>> B(2, vector<ll>(3));
      for (int i=0;i<2;i++){
        for (int j=0;j<n;j++){
          if (j < n/2)  {
            B[i][0] += A[i][j];
          } else if (j == n/2) {
            B[i][1] += A[i][j];
          } else {
            B[i][2]+=A[i][j];
          }
        }
      }
      A = B;
      n = 3;
    }
  }
  vector<vector<int>> vis(2, vector<int>(n));
  vis[0][0] = true;
  vis[1][n-1] = true;
  int timer = 0;
  auto dfs = [&](auto&& self, int turn, array<pair<int,int>,2> p) -> array<ll,2> {
    timer++;
    bool yes = true;
    for (auto x : vis) {
      for (auto y : x) {
        if (!y) yes = false;
      }
    }
    if (timer > 2*n+1 || yes) {
      timer--;
      if (yes) return {0,0};
      return {-(ll)1e18,-(ll)1e18};
    }
    auto [x,y] = p[turn];
    pair<int,int> cands[] = {{x+1,y},{x-1,y},{x,y+1},{x,y-1}};
    auto mx = self(self, turn^1, p);
    for (auto [i,j] : cands) {
      if (i < 0 || j < 0 || i >= 2 || j >= n) continue;
      bool vv = !vis[i][j];
      if (vis[i][j]) continue;
      vis[i][j] ++;
      p[turn] = {i,j};
      auto score = self(self, turn^1, p);
      if (vv) score[turn] += A[i][j];
      if (mx[turn] < score[turn] || (mx[turn] == score[turn] && mx[turn^1] > score[turn^1]))  {
        mx = score;
      }
      //cout << turn << " " << mx[0] << " " << mx[1] << " " << i << " " << j << "\n";
      vis[i][j] --;
    }
    timer--;
    return mx;
  };
  auto ans = dfs(dfs, 0, {{{0,0}, {1,n-1}}});
  ans[0] += A[0][0]; ans[1] += A[1][n-1];
  cout << ans[0] << " " << ans[1] << "\n";
  // RIP my masterpiece casework
/*   if (n%2 == 0) { */
/*     cout << A[0][0] + max(A[0][1], A[1][0]) << " " << A[1][1] + min(A[0][1],A[1][0]) << "\n"; */
/*   } else { */
/*     pair<ll,ll> c1 = {A[0][0] + A[1][0],0}; */
/*     c1.second = sum - c1.first; */
/*     pair<ll,ll> c2 = {A[0][0] + A[1][0] + A[0][1] + A[1][1], 0}; */
/*     c2.second = sum - c2.first; */
/*     pair<ll,ll> c3 = {A[0][0] + A[0][1] + A[0][2], 0}; */
/*     c3.second = sum - c3.first; */
/*     if (c3.second > c2.second) { */
/*       c2 = c3; */
/*     } */
/*     c1 = max(c1,c2); */
/*     cout << c1.first << " " << c1.second << "\n"; */
/*   } */
/* } */
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
