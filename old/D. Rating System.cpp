#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i=0;i<n;i++){
		cin >> A[i];
	}
	pair<ll, ll> ans = {0, 0};
	ll cur = 0;
	ll start = 0;
	ll pf = 0;
	for (int i=0;i<n;i++){
		cur += A[i];
		pf += A[i];
		if (cur > 0) {
			cur = 0;
			start = pf;
		}
		ans = min(ans, {cur, start});
	}
	cout << ans.second << "\n";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
