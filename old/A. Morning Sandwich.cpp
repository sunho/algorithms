#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int a,b,c;
		cin >> a >> b >> c;
		int k = b + c;
		if (a == 0) {
			cout << 0 << "\n";
			continue;
		}
		--a;
		int ans = 1;
		ans += 2*min(a,k);
		cout << ans << "\n";
	}
}
