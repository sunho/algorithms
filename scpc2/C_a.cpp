#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i=0;i<n;i++){
		cin >> A[i];
	}
	map<vector<int>,int> S;
	for (int j=0;j<2*n;j++){
		if (S.count(A)) {
			cout << j - S[A] << "\n";
			return;
		}
		S[A] = j;
		vector<int> nxt = A;
		for (int i=0;i<n;i++) {
			if (A[i] > 0) {
				nxt[i] --;
				nxt[(i+1)%n] ++;
			}
		}
		A = nxt;
	}
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
