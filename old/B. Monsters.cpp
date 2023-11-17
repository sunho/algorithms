#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		vector<pair<int,int>> vals(n);
		for (int i=0;i<n;i++){
			int a;
			cin >> a;
			vals[i] = {(a%k == 0) ? -2e9 : -(a%k), i};
		}
		sort(begin(vals), end(vals));
		for (auto [_,i] : vals) {
			cout << i + 1 << " ";
		}
		cout << "\n";
	}
}
