#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1e9;
struct seg_tree {
  int n;
  vector<int> bits;
  seg_tree(int n) : n(n), bits((n+1)*2, -inf) {}

  int combine(int a, int b) { return max(a,b); }
  void update(int k, int x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2) bits[k] = combine(bits[k*2], bits[k*2+1]);
  }
  int query(int l, int r) {
    int res = -inf;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1) res = combine(res, bits[l++]);
      if (!(r & 1)) res = combine(res, bits[r--]);
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  
  vector<vector<int>> adj(n);

  for (int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    --a,--b;
    adj[a].push_back(b);
  }
  for (auto& arr : adj) {
    sort(rbegin(arr), rend(arr));
  }

  seg_tree st(n+1);
  st.update(0, 0);
  
  for (int i=0;i<n;i++){
    for (int b : adj[i]) {
      st.update(b, b == 0 ? 1 : st.query(0, b-1)+1);
    }
  }

  cout << st.query(0,n-1) << "\n";
}
