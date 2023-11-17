#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << 1 << "\n";
			continue;
		}
		if (n == 2) {
			cout << 1 << " " << 2 << "\n";
			continue;
		}
		cout << 2 << " ";
		int cur = 4;
		for (int i = 0; i < (n-3)/2; i++){
			cout << cur++ << " ";
		}
		cout << 1 << " ";
		for (int i=0;i<(n-3+1)/2;i++) {
			cout << cur++ << " ";
		}
		cout << 3 << "\n";
	}
}
