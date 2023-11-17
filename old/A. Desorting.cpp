#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> A(n);
		for (int i=0;i<n;i++) {
			cin >> A[i];
		}
		int ans = 1e9;
		for (int i=0;i<n-1;i++){
			if (A[i] <= A[i+1]) {
				ans = min(ans, (A[i+1]-A[i])/2+1);
			} else {
				ans = 0;
			}
		}
		cout << ans << "\n";
	}
}
