#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

struct fenwick_tree {
  // [-bias, n - bias)
  fenwick_tree(int n) : sums(n) {}
  void update(int pos, ll dif) { // a[pos] += dif
    for (; pos < (int)sums.size(); pos |= pos + 1) sums[pos] += dif;
  }
  ll query(int pos) { // sum of values in [0, pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += sums[pos-1];
    return res;
  }
  ll query(int l, int r) { // sum of values in [l, r)
    return query(r) - query(l);
  }
private:
  vector<ll> sums;
};

void solve() {
  int n,m,q;
  cin >> n >> m >> q;
  fenwick_tree cols(m);
  vector<fenwick_tree> ele(m, fenwick_tree(n));
  int I = 0;
  vector<vector<char>> M(n, vector<char>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> M[i][j];
      if (M[i][j] == '*') {
        ele[j].update(i, 1);
        cols.update(j, 1);
        I++;
      }
    }
  }
  auto query = [&](){
    int c = I/n;
    int r = I%n;
    int rem1 = c*n - (int)cols.query(0,c);
    int rem2 = 0;
    if (c < m) {
      rem2 = r - (int)ele[c].query(0,r);
    }
    return rem1 + rem2;
  };
  while(q--) {
    int i,j;
    cin >> i >> j;
    --i,--j;
    if (M[i][j] == '*') {
      I--;
      cols.update(j,-1);
      ele[j].update(i,-1);
      M[i][j] = '.';
    } else {
      I++;
      cols.update(j,1);
      ele[j].update(i,1);
      M[i][j] = '*';
    }
    cout << query() << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
