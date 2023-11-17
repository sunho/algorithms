#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

// https://cp-algorithms.com/string/z-function.html#efficient-algorithm-to-compute-the-z-function
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve(const string& R, const string& P) {
	int n = R.size();
	const int inf = 1e9;
	vector<int> dp(n+1, inf);
	dp[0] = 0;
	set<pair<int,int>> set_queue;	
	vector<vector<pair<int,int>>> to_remove(n+1);
	string S = P + "$" + R;
	auto Z = z_function(S);
	Z = vector(Z.begin()+P.size()+1,Z.end());
	for (int i=0;i<=n;i++){
		if (!set_queue.empty()) 
			dp[i] = min(dp[i], set_queue.begin()->first);
		for (auto& p : to_remove[i]) {
			set_queue.erase(p);
		}
		if (i < n) {
			if (Z[i] != 0) {
				pair<int,int> pp = {dp[i]+1, i+Z[i]};
				set_queue.insert(pp);
				to_remove[i+Z[i]].push_back(pp);
			}
		}
	}
	if (dp[n] == inf) {
		cout << -1 << "\n";
	} else {
		cout << dp[n] << "\n";
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin >> T;
	for(int t=0;t<T;t++) {
		cout << "Case #" << t+1 << "\n";
		string R, P;
		cin >> R >> P;
		solve(R, P);
	}

	return 0;
}
