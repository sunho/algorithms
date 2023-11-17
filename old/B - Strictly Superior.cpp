#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n,m;
	cin >> n >> m;
	vector<int> P(n);
	vector<set<int>> F(n);
	for (int i=0;i<n;i++){
		cin >> P[i];
		int c;
		cin >> c;
		for (int j=0;j<c;j++){
			int a;
			cin >> a;
			F[i].insert(a);
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i == j) continue;
			if (!all_of(begin(F[i]), end(F[i]), [&](int a) {
				return F[j].count(a);
			})) continue;
			if (P[i] == P[j] && F[i].size() < F[j].size()) {
				cout << "Yes";
				return 0;
			}
			if (P[i] > P[j]) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
}
