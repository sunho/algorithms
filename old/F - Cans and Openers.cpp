#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<int> free, regular, openers;
	for (int i=0;i<n;i++){
		int t,x;
		cin >> t >> x;
		if (t == 0) {
			free.push_back(x);
		} else if (t == 1) {
			regular.push_back(x);
		} else {
			openers.push_back(x);
		}
	}
	sort(begin(free),end(free), greater<>());
	sort(begin(regular),end(regular), greater<>());
	sort(begin(openers),end(openers), greater<>());
	vector<ll> pf(openers.size()+1);
	for (int i=0;i<openers.size();i++){
		pf[i+1] = pf[i] + openers[i];
	}
	vector<ll> free_pf(free.size()+1);
	for (int i=0;i<free.size();i++){
		free_pf[i+1] = free_pf[i] + free[i];
	}
	ll ans = 0;
	ll sum = 0;
	for (int d=0;d<=regular.size();d++){
		int k = lower_bound(begin(pf), end(pf), d) - begin(pf);
		if (m - k - d < 0 || k == pf.size()) continue;
		ll cand = free_pf[min((int)free.size(),m-k-d)] + sum;
		ans = max(ans,cand);
		if (d != regular.size()){
			sum += regular[d];
		}
	}
	cout << ans << "\n";
}
