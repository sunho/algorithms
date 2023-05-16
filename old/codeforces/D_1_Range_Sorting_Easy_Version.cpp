#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ilog2(int x) {
  return 32-__builtin_clz(x)-1;
}

struct sparse_table {
  vector<vector<int>> st;
  sparse_table(const vector<int>& A) {
    const int n = A.size();
    st = vector(32, vector(n, 0));
    for (int i=0;i<n;i++) st[0][i] = A[i];
    for (int i=0;i<ilog2(n);i++){
      for (int j=1<<i;j<n;j++) {
        st[i+1][j] = max(st[i][j], st[i][j-(1<<i)]);
      }
    }
  }
  int query(int l, int r) {
    int i = ilog2(r-l+1);
    return max(st[i][l+(1<<i)-1], st[i][r]);
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  stack<pair<int,int>> stk;
  vector<int> pos_left(n, -1), pos_right(n, n);
  for (int i=0;i<n;i++) {
    while (!stk.empty() && stk.top().first > A[i]) {
      stk.pop();
    }
    if (!stk.empty()) pos_left[i] = stk.top().second;
    stk.push({A[i], i});
  }
  while (!stk.empty()) stk.pop();
  for (int i=n-1;i>=0;i--) {
    while (!stk.empty() && stk.top().first > A[i]) {
      stk.pop();
    }
    if (!stk.empty()) pos_right[i] = stk.top().second;
    stk.push({A[i], i});
  }
  while (!stk.empty()) stk.pop();
  sparse_table st(A);
  auto lb = [&](int r, int x) {
    int ng=-1, ok=r+1;
    while (ok-ng > 1) {
      int mid = (ok+ng)/2;
      if (st.query(mid,r) < x) ok = mid;
      else ng = mid;
    }
    return ok;
  };
  ll ans = 0;
  for (int i=0;i<n;i++){
    ans += (ll)i*(n-i);
  }
  for (int i=0;i<n;i++) {
    int k = pos_left[i];
    if (k < 0) continue;
    int x = lb(k-1, A[i]);
    int y = pos_right[i];
    ll cnt = (ll)(k-x+1)*(y-i);
    assert(cnt >= 0);
    ans -= cnt;
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
