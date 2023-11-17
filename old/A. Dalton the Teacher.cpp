#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<int> A(n);
		for (int i=0;i<n;i++)
			cin >> A[i];
		int cnt = 0;
		for (int i=0;i<n;i++){
			if (A[i] == i+1)
				cnt ++;
		}
		cout << (cnt + 1)/2 << "\n";
	}
}
