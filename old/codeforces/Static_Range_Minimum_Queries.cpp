#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int ilog2(int x) {
  return 32-__builtin_clz(x)-1;
}

struct sparse_table {
  vector<vector<int>> st;
  sparse_table(const vector<int>& a) : st(1, a) {
    for (int i=0;i<ilog2(a.size());i++){
      st.emplace_back(a.size());
      for (int j=1<<i;j<a.size();j++) {
        st[i+1][j] = min(st[i][j], st[i][j-(1<<i)]);
      }
    }
  }
  int query(int l, int r) {
    int i = ilog2(r-l+1);
    return min(st[i][l+(1<<i)-1], st[i][r]);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,q;
  cin >> n >> q;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  sparse_table st(A);
  while (q--) {
    int l,r;
    cin >> l >> r;
    --l,--r;
    cout << st.query(l, r) << "\n";
  }
}
