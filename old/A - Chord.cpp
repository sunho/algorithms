#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	vector<string> A = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};
	string s;
	cin >> s;
	if (find(begin(A), end(A), s)  == end(A)) {
		cout << "No" << "\n";
	} else {
		cout << "Yes" << "\n";
	}
}
