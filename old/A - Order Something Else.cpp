#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, p, q;
	cin >> n >> p >> q;
	vector<int> A(n);
	for (int i=0;i<n;i++) cin >> A[i];
	cout << min(p, q+*min_element(begin(A), end(A)));
}
