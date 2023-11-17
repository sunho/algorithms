#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string S;
	cin >> S;
	int n = S.size();
	int m;
	cin >> m;
	string L,R;
	cin >> L >> R;
	vector<vector<int>> idx(10);
	for (int i=0;i<n;i++){
		idx[S[i]-'0'].push_back(i);
	}
	for (int i=0;i<10;i++){
		idx[i].push_back(n);
	}
	vector<bool> dp(n+2);
	dp[0] = true;
	for (int i=0;i<m;i++) {
		vector<bool> next(n+2);
		for (int j=0;j<=n;j++) {
			if (!dp[j]) continue;
			for (int d=0;d<10;d++){
				char dd = '0'+d;
				if (dd < L[i] || dd > R[i]) continue;
				next[*lower_bound(begin(idx[d]), end(idx[d]), j)+1] = true;
			}
		}
		if (next[n+1]) {
			cout << "YES" << "\n";
			return;
		}
		dp = next;
	}
	cout << "NO" << "\n";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
