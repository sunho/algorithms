#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> A(n);
		for (int i=0;i<n;i++) cin >> A[i];
		array<ll,2> ans{};
		ll mx = -1e18;
		for (int i=0;i<n;i++){
			ans[i&1] += max(0ll, A[i]);
			mx = max(mx, A[i]);
		}
		if (mx < 0) {
			cout << mx << "\n";
			continue;
		}
		cout << max(ans[0], ans[1]) << "\n";
	}
}
