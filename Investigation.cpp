#include <bits/stdc++.h>
#include <queue>
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
  int n,m;
  cin >> n >> m;
  vector adj(n, vector<pair<int, int>>());
  while (m--){
    int a,b,w;
    cin >> a >> b >> w;
    --a,--b;
    adj[a].push_back({b,w});
  }
  vector<mint> cnt(n,0);
  cnt[0] = 1;
  ll linf = 1e18;
  vector<ll> dist(n, linf);
  int inf = 1e9;
  vector<int> min_fligts(n, inf);
  vector<int> max_fligts(n, -inf);
  min_fligts[0] = 0;
  max_fligts[0] = 0;
  priority_queue<tuple<ll,int, int>> pq;
  pq.push({0,0, -1});
  while (!pq.empty()) {
    auto [d, u, p] = pq.top();
    d *= -1;
    pq.pop();
    if (dist[u] >= d) {
      if (p != -1) {
        min_fligts[u] = min(min_fligts[u], min_fligts[p] + 1);
        max_fligts[u] = max(max_fligts[u], max_fligts[p] + 1);
      }
      cnt[u] += cnt[p];
    }
    if (dist[u] != linf) {
      continue;
    }
    dist[u] = d;
    for (auto [v,w] : adj[u]) {
      pq.push({-(d+w), v, u});
    }
  }
  cout << dist[n-1] << " " << cnt[n-1].val() << " " << min_fligts[n-1] << " " << max_fligts[n-1] << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
