#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n,k,x;
	cin >> n >> k >> x;
	vector<int> ans;
	if (k == 1 && x == 1) {
		cout << "NO" << "\n";
		return;
	}
	if (x != 1) {
		for (int i=0;i<n;i++){
			ans.push_back(1);
		}
	} else {
		if (n % 2 == 0) {
			for (int i=0;i<n/2;i++){
				ans.push_back(2);
			}
		} else {
			if (n == 1 || k == 2) {
				cout << "NO" << "\n";
				return;
			}
			ans.push_back(3);
			for (int i=0;i<(n-3)/2;i++){
				ans.push_back(2);
			}
		}
	}
	cout << "YES" << "\n";
	cout << ans.size() << "\n";
	int sum = 0;
	for (int a : ans) {
		cout << a << " ";
		sum += a;
	}
	assert(sum == n);
	cout << "\n";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
