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
  int n, m;
  cin >> n >> m;
  vector adj(n, vector<int>());
  while (m--){
    int a,b;
    cin >> a >> b;
    --a,--b;
    adj[b].push_back(a);
  }
  vector<bool> vis(n);
  queue<int> q;
  vector<mint> dp(n);
  dp[0] = 1;
  vector<int> order;
  auto dfs = [&](auto self, int u) -> void {
    vis[u] = true;
    for (int v : adj[u]) {
      if (!vis[v])
        self(self, v);
    }
    order.push_back(u);
  };
  for (int i=0;i<n;i++)
    if (!vis[i])
      dfs(dfs, i);

  for (int i : order) {
    for (int v : adj[i]) {
      dp[i] += dp[v];
    }
  }

  cout << dp[n-1].val() << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
