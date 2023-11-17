#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
	int n, d;
	cin >> n >> d;
	vector<int> pos, neg;
	for (int i=0;i<n;i++){
		int a;
		cin >> a;
		if (a >= 0)
			pos.push_back(a);
		else
			neg.push_back(-a);
	}
	sort(begin(pos),end(pos));
	sort(begin(neg),end(neg));
	int ans = 0;
	for (int i=0;i<pos.size();i++){
		if (pos[i] > d) {
			continue;
		}
		int add = upper_bound(begin(neg),end(neg),d-2*pos[i]) - begin(neg);
		ans = max(ans, i+1+add);
	}
	for (int i=0;i<neg.size();i++){
		if (neg[i] > d) {
			continue;
		}
		int add = upper_bound(begin(pos),end(pos),d-2*neg[i]) - begin(pos);
		ans = max(ans, i+1+add);
	}
	cout << ans << "\n";
}

int main() {
	
	int T;
	cin >> T;
	for(int t=0;t<T;t++) {
		cout << "Case #" << t+1 << "\n";
		solve();
	}

	return 0;
}
