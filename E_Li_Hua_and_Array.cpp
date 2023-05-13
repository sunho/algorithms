#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e6+10;
vector<int> phi(N+1);
vector<int> levels(N+1);
vector<int> tin(N+1);
vector<int> tout(N+1);
vector<array<int,6>> up(N+1);
int l = 0;

bool is_ancestor(int p, int u) {
  return tin[p] <= tin[u] && tout[u] <= tout[p];
}

int get_lca(int u, int v) {
  if (is_ancestor(u, v)) return u;
  if (is_ancestor(v, u)) return v;
  for (int k=l-1;k>=0;k--){
    if (!is_ancestor(up[u][k], v))
      u = up[u][k];
  }
  return up[u][0];
}

int get_up(int n, int k) {
  for (int i=0;i<l;i++){
    if (k & (1<<i)) {
      n = up[n][i];
    }
  }
  return n;
}

template <class T> struct seg_tree {
  int n;
  vector<T> bits;
  seg_tree(int n) : n(n), bits((n+1)*2) {}

  void update(int k, T x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2) bits[k] = bits[k*2] + bits[k*2+1];
  }
  T query(int l, int r) {
    T resl = {}, resr = {};
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1) resl = resl + bits[l++];
      if (!(r & 1)) resr = bits[r--] + resr;
    }
    return resl + resr;
  }
};
const int inf = 1e9;
struct node {
  int val = 0;
  ll cost = 0;
  int sz = 1;
  friend node operator+(node lhs, node rhs) {
    if (lhs.val == 0) return rhs;
    if (rhs.val == 0) return lhs;
    int lca = get_lca(lhs.val, rhs.val);
    ll dx = ((ll)levels[lhs.val]-levels[lca])*lhs.sz;
    ll dy = ((ll)levels[rhs.val]-levels[lca])*rhs.sz;
    node res = {};
    res.sz = lhs.sz + rhs.sz;
    res.cost = lhs.cost + rhs.cost + dx + dy;
    res.val = lca;
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  phi[0] = 0;
  phi[1] = 1;
  for (int i = 0; i <= N; i++)
    phi[i] = i;

  for (int i = 2; i <= N; i++) {
    if (phi[i] == i) {
      for (int j = i; j <= N; j += i)
        phi[j] -= phi[j] / i;
    }
  }

  vector adj(N+1, vector<int>());
  for (int i=2;i<=N;i++){
    levels[i] = levels[phi[i]]+1;
    adj[phi[i]].push_back(i);
    l = max(l,(int)ceil(log2(levels[i]+1)));
  }

  int timer = 0;
  auto dfs = [&](auto self, int u) -> void {
    tin[u] = ++timer;
    for (int v : adj[u]) {
      self(self, v);
    }
    tout[u] = ++timer;
  };
  dfs(dfs, 1);

  
  for (int k=0;k<l;k++){
    for (int i=0;i<=N;i++){
      if (k == 0)
        up[i][k] = phi[i];
      else
        up[i][k] = up[up[i][k-1]][k-1];
    }
  }

  int n, q;
  cin >> n >> q;

  set<int> rem;
  vector<int> A(n);
  seg_tree<node> st(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
    st.update(i, {A[i]});
    if (A[i] != 1) {
      rem.insert(i);
    }
  }

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l,r;
      cin >> l >> r;
      --l,--r;
      for (auto it = rem.lower_bound(l); it != rem.end();) {
        int j = *it;
        if (j > r)
          break;
        A[j] = phi[A[j]];
        st.update(j, {A[j]});
        if (A[j] == 1) 
          it = rem.erase(it);
        else
          it++;
      }
    } else {
      int l,r;
      cin >> l >> r;
      --l,--r;
      cout << st.query(l,r).cost << "\n";
    }
  }
}

