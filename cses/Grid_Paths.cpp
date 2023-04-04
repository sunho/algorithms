#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Modular Integer
// does arithematics (mod P) automatically
int P = 1000000007; // 998244353
struct mint {
  int x;
  int norm(int x) const { if (x < 0) { x += P; } if (x >= P) { x -= P; } return x; }
  mint(int x = 0) : x(norm(x)) {}
  mint(ll x) : x(norm(x % P)) {}
  int val() const { return x; }
  mint power(int n) { mint res = 1; mint a = *this; while (n) { if (n % 2) res = res * a; a = a * a; n /= 2; } return res; }
  mint inv() { return power(P-2); }
  mint& operator*=(const mint& rhs) { x = norm(((ll)x * rhs.x)%P); return *this; }
  mint& operator+=(const mint& rhs) { x = norm(x + rhs.x); return *this; }
  mint& operator-=(const mint& rhs) { x = norm(x - rhs.x); return *this; }
  #define OP(OO, OOE) friend mint operator OO(mint lhs, mint rhs) { mint res = lhs; res OOE rhs; return res; }
  OP(*, *=)
  OP(+, +=)
  OP(-, -=)
};

void solve() {
  int n;
  cin >> n;
  vector M(n, vector(n, ' '));
  vector dp(n, vector(n, mint(0)));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> M[i][j];
    }
  }
  if (M[0][0] == '*') {
    cout << 0 << "\n";
    return;
  }
  vector vis(n, vector(n, false));
  dp[0][0] = 1;
  queue<pair<int,int>> q;
  q.push({0,0});
  vis[0][0] = true;
  while(!q.empty()) {
    auto [i,j] = q.front();
    q.pop();
    pair<int,int> cands[] = {{i+1,j},{i,j+1}};
    for (auto [x,y] : cands) {
      if (x<0 || x>=n || y<0 || y>=n) continue;
      if (M[x][y] == '*') continue;
      dp[x][y] += dp[i][j];
      if (vis[x][y]) continue;
      vis[x][y] = true;
      q.push({x,y});
    }
  }
  cout << dp[n-1][n-1].val() << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
