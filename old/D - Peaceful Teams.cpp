#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, t, m;
	cin >> n >> t >> m;
	vector<vector<int>> hate(n);
	for (int i=0;i<m;i++) {
		int u,v;
		cin >> u >> v;
		--u,--v;
		hate[u].push_back(v);
		hate[v].push_back(u);
	}
	int cur_teams = 0;
	vector<vector<int>> bans(t+1, vector<int>(n));
	ll ans = 0;
	auto dfs = [&](auto self, int cur) {
		if (cur == n) {
			if (cur_teams == t)
				ans++;
			return;
		}
		int rem_p = n - cur;
		int rem_t = t - cur_teams;
		if (rem_t > rem_p) {
			return;
		}
		if (rem_t < rem_p) {
			for (int i=0;i<cur_teams;i++){
				if (bans[i][cur]) continue;
				for (int v : hate[cur]) {
					bans[i][v]++;
				}
				self(self, cur + 1);
				for (int v : hate[cur]) {
					bans[i][v]--;
				}
			}
		}
		if (cur_teams < t) {
			for (int v : hate[cur]) {
				bans[cur_teams][v]++;
			}
			cur_teams++;
			self(self, cur + 1);
			cur_teams--;
			for (int v : hate[cur]) {
				bans[cur_teams][v]--;
			}
		}
	};
	dfs(dfs, 0);
	cout << ans << "\n";
}
