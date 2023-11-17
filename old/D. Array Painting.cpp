#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i=0;i<n;i++){
		cin >> A[i];
		if (i == 0 || i == n-1) {
			if (A[i] == 2) {
				A[i] = 1;
			}
		}
	}
	vector<bool> visited(n);
	auto dfs = [&](auto& self, int i, int c) -> void {
		visited[i] = true;
		int cands[] = {i-1,i+1};
		if (A[i] == 0) return;
		for (int x : cands) {
			if (x < 0 || x >= n) continue;
			if (visited[x]) continue;
			if (A[x] == 0) {
				c--;
				if (c >= 0) {
					self(self, x, c);
				}
			} else {
				self(self, x, c);
			}
		}
	};
	int ans = 0;
	for (int i=0;i<n;i++){
		if (A[i] == 2 && !visited[i]) {
			dfs(dfs, i, 2);
			ans ++;
		}
	}
	for (int i=0;i<n;i++){
		if (A[i] == 1 && !visited[i]) {
			dfs(dfs, i, 1);
			ans ++;
		}
	}
	for (int i=0;i<n;i++) {
		if (!visited[i]) {
			ans++;
		}
	}
	cout << ans << "\n";
}
