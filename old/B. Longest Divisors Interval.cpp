#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll x;
	cin >> x;
	for (int i=1;i<=x;i++){
		if (x%i != 0) {
			cout << i - 1 << "\n";
			return;
		}
	}
	cout << x << "\n";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
