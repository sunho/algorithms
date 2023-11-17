#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	for (int i=1;i<=26;i++) {
		if (n % i != 0) {
			for (int j=0;j<n;j++) {
				cout << (char)('a' + (j % i));
			}
			cout << "\n";
			return;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
