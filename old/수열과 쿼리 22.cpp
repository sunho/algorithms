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
  ll query(int l, int r) { return query(r) - query(l-1); }
};

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n;
	cin >> n;
	fenwick_tree ft(n);
	vector<int> A(n);
	for (int i=0;i<n;i++) {
		cin >> A[i];
		ft.update(i, A[i]);
	}

	int q;
	cin >> q;
	vector<pair<int,int>> updates;
	vector<tuple<int,int,int,int>> queries;
	for (int j=0;j<q;j++){
		int a;
		cin >> a;
		if (a == 1) {
			int i,k;
			cin >> i >> k;
			--i;
			updates.push_back({i,k});
		} else {
			int k,l,r;
			cin >> k >> l >> r;
			--k,--l,--r;
			queries.push_back({k,l,r,queries.size()});
		}
	}
	sort(begin(queries), end(queries));
	vector<ll> ans(queries.size());
	int cur_k = -1;
	for (auto [k,l,r,j] : queries) {
		while (cur_k != k) {
			cur_k++;
			auto [i,a] = updates[cur_k];
			ft.update(i, a-A[i]);
			A[i] = a;
		}
		ans[j] = ft.query(l,r);
	}
	for (int i=0;i<queries.size();i++) {
		cout << ans[i] << "\n";
	}
}
