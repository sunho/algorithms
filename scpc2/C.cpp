#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

// 출저: https://cp-algorithms.com/string
vector<int> z_function(string s) {
  int n = s.size();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r)
      z[i] = min(z[i-l], r-i+1);
    while (i + z[i] < n && s[i+z[i]] == s[z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i, r = i + z[i] - 1;
    }
  }
  return z;
}

void solve(int n) {
	string A(n, ' ');
	for (int i=0;i<n;i++){
		cin >> A[i];
	}
	//auto res = z_function(A);
	for (int i=1;i<n;i++){
		if (n % i != 0) continue;
		auto B = A;
		rotate(begin(B), begin(B) + i, end(B));
		if (B == A) {
			cout << i << "\n";
			return;
		}
	}
	cout << n << "\n";
}

void solve_2(int n) {
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
		int n;
		cin >> n;
		if (n <= 1000) {
			solve_2(n);
		} else {
			solve(n);
		}
	}

	return 0;
}
