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
  int scc;

  DSU(int N) { 
    e.assign(N, 1);
    p.assign(N, 0);
    for(int i = 0; i < N; i++) p[i] = i;
    scc = N;
  }

  // get representive component (uses path compression)
  int get(int x) { 
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
  }
  bool same_set(int a, int b) { return get(a) == get(b); }
  int size(int x) { return e[get(x)]; }
  bool unite(int x, int y) {  // union by size
    x = get(x), y = get(y);
    if (x == y) return false;
    if (e[x] < e[y]) 
      swap(x, y);
    e[x] += e[y];
    p[y] = x;
    scc--;
    return true;
	}
};
void solve() {
  int n;
  cin >> n;
  DSU dsu(n);
  vector<tuple<int,int,int>> A(n);
  for(int i=0;i<n;i++){
    int a,b;                                                                                                                                                                                                                                                                                                                                                                                                                    
    cin >> a >> b;
    A[i] = {a,b,i};
  }
  sort(all(A));
  set<int> S;
  set<int> R;
  for(int i=1;i<=n;i++){
    R.insert(i);
  }
  for(int i=0;i<n-1;i++){
    auto [x,y,id] = A[i];
    auto [x2,y2,id2] = A[i+1];
    S.insert(y);
    R.erase(y);
    if (!(*S.begin() > *--R.end())) {
      dsu.unite(id, id2);
    }
  }
  for(int i=0;i<n;i++){
    cout << dsu.size(i) << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
