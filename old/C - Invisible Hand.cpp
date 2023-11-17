#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<int> A(n);
	vector<int> B(m);
	for (int i=0;i<n;i++)
		cin >> A[i];
	for (int i=0;i<m;i++)
		cin >> B[i];
	sort(begin(A),end(A));
	sort(begin(B),end(B));
	int ng = -1, ok = (int)1e9+1;
	auto check = [&](int x) {
		int sell = 0, buy = 0;
		for (int i=0;i<n;i++){
			if (A[i] <= x)
				sell++;
		}
		for (int i=0;i<m;i++){
			if (B[i] >= x)
				buy++;
		}
		return sell >= buy;
	};
	while (ok - ng > 1) {
		int mid = (ok+ng) >> 1;
		if (check(mid))
			ok = mid;
		else
			ng = mid;
	}
	cout << ok << "\n";
}
