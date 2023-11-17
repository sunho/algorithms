#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n,m;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<int> zero(n,-1), ones(n, n);
		for (int i=0;i<n;i++){
			if (s[i] == '0') {
				zero[i] = i;
			} else {
				if (i != 0) {
					zero[i] = zero[i-1];
				}
			}
		}
		for (int i=n-1;i>=0;i--){
			if (s[i] == '1') {
				ones[i] = i;
			} else {
				if (i != n-1) {
					ones[i] = ones[i+1];
				}
			}
		}
		set<pair<int,int>> S;
		for (int i=0;i<m;i++){
			int l,r;
			cin >> l >> r;
			--l,--r;
			l = ones[l];
			r = zero[r];
			if (l > r) {
				S.insert({0,0});
			} else {
				S.insert({l,r});
			}
		}
		cout << S.size() << "\n";
	}
}
