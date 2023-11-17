#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1e9;

struct slide_window {
  deque<pair<int,int>> q;
  int l = 0, r = 0;
  slide_window() = default;
  void add(int x) {
    while (!q.empty() && q.back().first <= x) {
      q.pop_back();
    }
    q.push_back({x,r});
    ++r;
  }
  void remove() {
    if (q.front().second == l) q.pop_front();
    ++l;
  }
  int query() {
    return q.empty() ? -inf : q.front().first;
  }
  size_t size() { return r-l; }
};

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> pos;
  pos.push_back(-1);
  for (int i=0;i<n;i++) {
    cin >> A[i];
    if (A[i] == 2) {
      pos.push_back(i);
    }
  }
  pos.push_back(n);
  int m, t;
  cin >> m >> t;
  vector dp(n, -inf);
  vector<int> pf(n+1, -inf);
  while (m--) {
    vector nxt = dp;
    slide_window window;
    pf[0] = 0;
    int curi = 0;
    for (int i=0;i<n;i++) {
      pf[i+1] = max(pf[i], dp[i]+i);
      int x = pos[curi], y = pos[curi+1];
      if (A[i] == 2) {
        curi++;
        x = pos[curi-1], y = pos[curi+1];
      }
      int mn = min(i-x-1,t);
      int dy = min(y-i-1,t);
      int dy2 = min(y-i,t);
      int cand = 1+mn+dy;
      if (i-mn-1>=0) 
        cand += pf[i-mn-1];
      if (i-x<=t && x >= 0) 
        cand = max(cand, dp[x] + x + 2 + mn + dy);
      if (i != 0) 
        cand = max(cand, window.query() + i + dy);
      if (A[i] == 2)
        window = slide_window();
      window.add(dp[i]);
      if (window.size() > t+1) window.remove();
      int nx = min(i+dy2,n-1);
      cand -= nx;
      nxt[nx] = max(nxt[nx], cand);
    }
    dp = nxt;
  }
  int ans = -inf;
  for (int i=0;i<n;i++) {
    ans = max(ans, dp[i] + i);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  for (int t=0;t<T;t++){
    cout << "Case #" << t+1 << "\n";
    solve();
  }
}
