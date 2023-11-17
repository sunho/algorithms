#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string> S(n);
	for (int i=0;i<n;i++) {
		cin >> S[i];
		string t = S[i];
		reverse(begin(t), end(t));
		if (S[i] > t) {
			S[i] = t;
		}
	}
	sort(begin(S), end(S));
	S.resize(unique(begin(S), end(S))-begin(S));
	cout << S.size();
}
