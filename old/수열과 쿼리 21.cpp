#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n+1) {}
  void update(int v, int delta) { 
    for (++v; v <= n; v += v&(-v)) bits[v] += delta;
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r&(-r)) res += bits[r];
    return res;
  }
  void update(int l, int r, int delta) { 
		update(r+1, -delta);
		update(l, delta);
	}
};

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> A(n);
	fenwick_tree ft(n);
	for (int i=0;i<n;i++) {
		cin >> A[i];
		ft.update(i,i,A[i]);
	}
	int q;
	cin >> q;
	while (q--){
		int a;
		cin >> a;
		if (a == 1) {
			int l,r,k;
			cin >> l >> r >> k;
			--l,--r;
			ft.update(l,r,k);
		} else {
			int x;
			cin >> x;
			--x;
			cout << ft.query(x) << "\n";
		}
	}
}
