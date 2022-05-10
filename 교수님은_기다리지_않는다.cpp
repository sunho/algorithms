#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

struct DSU {
  vector<int> e;
  vector<int> p;
  vector<ll> dist;
  int scc;

  DSU(int N) { 
    e.assign(N, 1);
    p.assign(N, 0);
    dist.assign(N, 0);
    for(int i = 0; i < N; i++) p[i] = i;
    scc = N;
  }

  // get representive component (uses path compression)
  int get(int x) { 
    if (x == p[x]) return x;
    int q =  get(p[x]);
    dist[x] += dist[p[x]];
    return p[x] = q;
  }
  bool same_set(int a, int b) { return get(a) == get(b); }
  int size(int x) { return e[get(x)]; }
  bool unite(int x, int y, ll w) {  // union by size
    int a = get(x), b = get(y);
    if (a == b) return false;
    if (e[a] < e[b]) {
      swap(x, y);
      swap(a,b);
      w *= -1;
    }
    e[a] += e[b];
    // a = p1 - x
    // b = p2 - y
    // p1 - p2
    // w = y - x
    dist[b] = dist[x] - dist[y] + w;
    p[b] = a;
    scc--;
    return true;
  }
};

void solve(int n, int q) {
  DSU dsu(n);
  while (q--) {
    char t;
    cin >> t;
    if (t == '!') {
      int a,b;
      ll w;
      cin >> a >> b >> w;
      --a,--b;
      dsu.unite(a,b,w);
    } else {
      int a,b;
      cin >> a >> b;
      --a,--b;
      int g1 = dsu.get(a);
      int g2 = dsu.get(b);
      if (g1 != g2) {
        cout << "UNKNOWN" << "\n";
      } else {
        cout << (dsu.dist[b] - dsu.dist[a]) << "\n";
      }
    }
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);

  while(true) {
    int n,q;
    cin >> n >> q;
    if (n == 0 && q == 0) break;
    solve(n,q);
  }

  return 0;
}
