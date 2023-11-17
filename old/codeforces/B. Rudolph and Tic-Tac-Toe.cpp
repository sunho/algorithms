#include <bits/stdc++.h>
using namespace std;

void solve() {
	array<array<char, 3>,3> M{};
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			cin >> M[i][j];
		}
	}
	for (char c : {'+','O','X'}) {
		for (int i=0;i<3;i++) {
			if (M[i][0] == M[i][1] && M[i][1] == M[i][2] && M[i][0] == c) {
				cout << c << "\n";
				return;
			}
			if (M[0][i] == M[1][i] && M[1][i] == M[2][i] && M[0][i] == c) {
				cout << c << "\n";
				return;
			}
		}
		if (M[0][0] == M[1][1] && M[1][1] == M[2][2] && M[0][0] == c) {
			cout << c << "\n";
			return;
		}
		if (M[0][2] == M[1][1] && M[1][1] == M[2][0] && M[0][2] == c) {
			cout << c << "\n";
			return;
		}
	}
	cout << "DRAW" << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

