#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> fib;

void solve() {
	int n,k;
	cin >> n >> k;
	ll ans = 0;
	if (k >= fib.size()) {
		cout << 0 << "\n";
		return;
	}
	for (int x=0;x<=n;x++) {
		ll delta = n - fib[k-1]*x;
		if (delta >= 0 && delta % fib[k] == 0) {
			ans++;
		}
	}
	cout << ans << "\n";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	fib.push_back(0);
	fib.push_back(1);
	fib.push_back(1);
	const int N = 2e5;
	while (true) {
		ll nw = fib[fib.size()-1] + fib[fib.size()-2];
		fib.push_back(nw);
		if (nw > N) break;
	}
	int t;
	cin >> t;
	while (t--){
		solve();
	}
}
