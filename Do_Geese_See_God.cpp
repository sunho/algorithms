#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
  pair<int,int> intv;
  char ch;
  ll cnt;
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string s;
  cin >> s;
  ll k;
  cin >> k;
  --k;

  const int n = s.size();
  const ll N = 1e18;
  vector<vector<vector<Node>>> child(n+1, vector<vector<Node>>(n+1));
  vector<vector<pair<int,ll>>> dp(n+1, vector<pair<int,ll>>(n+1, {-1,-1}));
  auto solve = [&](auto self, int l, int r) -> pair<int, ll> {
    if (dp[l][r].first != -1) {
      return dp[l][r];
    }
    auto& res = dp[l][r];
    if (l == r) {
      return res = {0,1};
    }
    if (r-l == 1) {
      return res = {1,1};
    }
    if (s[l] == s[r-1]) {
      auto [L,S] = self(self, l+1,r-1);
      child[l][r].push_back({{l+1,r-1}, s[l], S});
      return res = {L+2, S};
    }
    auto [L1,S1] = self(self, l+1,r);
    auto [L2,S2] = self(self, l,r-1);
    if (L1 == L2) {
      Node left = {{l+1,r}, s[l], S1};
      Node right = {{l,r-1}, s[r-1], S2};
      if (left.ch > right.ch) {
        swap(left,right);
      }
      left.cnt = min(left.cnt,N);
      child[l][r].push_back(left);
      if (left.cnt == N) {
        right.cnt = 0;
      } else {
        right.cnt = min(right.cnt, N-left.cnt);
        child[l][r].push_back(right);
      }
      return res = {L1+2, left.cnt+right.cnt};
    } else if (L1 < L2) {
      child[l][r].push_back({{l+1,r}, s[l], S1});
      return res = {L1+2, S1};
    } else {
      child[l][r].push_back({{l,r-1}, s[r-1], S2});
      return res = {L2+2, S2};
    }
  };
  auto [L, S] = solve(solve, 0, n);
  if (k >= S) {
    cout << "NONE" << "\n";
    return 0;
  }
  auto construct = [&](auto self, int l, int r, ll cnt) -> string {
    if (l == r) {
      assert(cnt == 0);
      return "";
    }
    if (r-l == 1) {
      assert(cnt == 0);
      return string(1, s[l]);
    }
    if (child[l][r].size() == 1) {
      auto [l2, r2] = child[l][r][0].intv;
      return child[l][r][0].ch + self(self, l2, r2, cnt) + child[l][r][0].ch;
    }
    auto left = child[l][r][0], right = child[l][r][1];
    if (cnt < left.cnt) {
      return left.ch + self(self, left.intv.first, left.intv.second, cnt) + left.ch;
    } else {
      return right.ch + self(self, right.intv.first, right.intv.second, cnt-left.cnt) + right.ch;
    }
  };
  auto t = construct(construct, 0, n, k);
  cout << t << "\n";
}
