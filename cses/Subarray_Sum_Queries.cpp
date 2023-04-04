#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

struct node {
  ll L = 0, R = 0, mx = 0, sum = 0;

  friend node operator+(node lhs, node rhs) {
    node res{};
    res.sum = lhs.sum + rhs.sum;
    res.L = max({lhs.sum + rhs.L, lhs.L, 0ll});
    res.R = max({lhs.R + rhs.sum, rhs.R, 0ll});
    res.mx = max({lhs.R + rhs.L, lhs.mx, rhs.mx, 0ll});
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,m;
  cin >> n >> m;
  seg_tree<node> st(n);
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    st.update(i, {a,a,a,a});
  }
  while(m--){
    int u, a;
    cin >> u >> a;
    --u;
    st.update(u, {a,a,a,a});
    cout << st.query(0,n-1).mx << "\n";
  }
}
