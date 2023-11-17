#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto app1(vector<ll> A, int n) {
  asfsdf
	vector<pair<int,int>> ans;
	set<pair<ll,int>> S;
	for (int i=0;i<n;i++) {
		S.insert({A[i], i});
	}
	auto [_, mx_i] = *--S.end();
	if (mx_i != 0) {
		ans.push_back({0,mx_i});	
		ans.push_back({0,mx_i});	
	}
	for (int i=1;i<n;i++){
		ans.push_back({i,i-1});
		ans.push_back({i,i-1});
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	vector<ll> A(n);
	for (int i=0;i<n;i++){
		cin >> A[i];
	}
	pair<int,int> cnt = {0,0};
	for (int i=0;i<n;i++){
		if (A[i] < 0) cnt.first ++;
		if (A[i] > 0) cnt.second ++;
	}
	bool neg = cnt.first > cnt.second;
	if (neg) {
		reverse(begin(A), end(A));
		for (int i=0;i<n;i++){
			A[i] *= -1;
		}
	}
	vector<pair<int,int>> ans;
	


	for (auto [i, j] : ans) {
		A[i] += A[j];
	}
	auto B = A;
	sort(begin(B), end(B));
	assert(A == B);

	if (neg) {
		for (auto& [i,j] : ans){
			i = n - i - 1;
			j = n - j - 1;
		}
	}
	cout << ans.size() << "\n";
	for (auto [i, j] : ans) {
		cout << i + 1 << " " << j + 1 << "\n";
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--){
		solve();
	}
}
