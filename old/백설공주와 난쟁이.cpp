
#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

const int inf = 1e9;
template<typename Info>
struct seg_tree {
  int n;
  vector<Info> info;
  seg_tree(int n) : n(n), info(4*n, Info()) {}
  void pull(int v) { info[v] = info[v*2] + info[v*2+1]; }
  void update(int v, int l, int r, int x, const Info& val) {
    if (r - l == 1) {
      info[v] = val;
      return;
    }
    int m = (l + r) / 2;
    if (x < m) update(v*2, l, m, x,  val);
    else update(v*2+1, m, r, x, val); 
    pull(v);
  }
  void update(int x, const Info& val) { update(1, 0, n, x, val); }
  Info query(int v, int l, int r, int x, int y) {
    if (l >= y || r <= x)
      return Info();
    if (l >= x && r <= y)
      return info[v];
    int m = (l + r) / 2;
    pull(v);
    return query(2*v, l, m, x, y) + query(2*v+1, m, r, x, y);
  }
  Info query(int l, int r) { return query(1, 0, n, l, r+1); }
};

int c;
vector<vector<int>> A;

struct node {
	int val = -1;
	int cnt = 0;
	int l=0,sz=0;
  friend node operator+(node lhs, node rhs) {
		if (lhs.val == -1) return rhs;
		if (rhs.val == -1) return lhs;
		node res = {};
		res.l = lhs.l;
		res.sz = lhs.sz + rhs.sz;
		assert(lhs.val >= 1 && lhs.val <= c);
		assert(rhs.val >= 1 && rhs.val <= c);
		int lhs_cnt = lower_bound(begin(A[lhs.val]), end(A[lhs.val]), res.l+res.sz) - lower_bound(begin(A[lhs.val]), end(A[lhs.val]), res.l);
		int rhs_cnt = lower_bound(begin(A[rhs.val]), end(A[rhs.val]), res.l+res.sz) - lower_bound(begin(A[rhs.val]), end(A[rhs.val]), res.l);
		if (lhs_cnt >= rhs_cnt) {
			res.val = lhs.val;
			res.cnt = lhs_cnt;
		} else {
			res.val = rhs.val;
			res.cnt = rhs_cnt;
		}
		return res;
	}
};

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n;
	cin >> n >> c;
	vector<int> a(n);
	A.assign(c+1,{});
	seg_tree<node> st(n);
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	
	for (int i=0;i<n;i++){
		A[a[i]].push_back(i);
		st.update(i, {a[i], 1, i , 1});
	}

	int q;
	cin >> q;
	while (q--) {
		int l,r;
		cin >> l >> r;
		--l,--r;
		auto res = st.query(l,r);
		if (2*res.cnt > (r-l+1)) {
			cout << "yes " << res.val << "\n";
		} else {
			cout << "no" << "\n";
		}
	}
}
