#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct P {
	int x,y;
};

void solve() {
	P A,B,C;
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
	auto side = [](int a0, int c0) -> int {
		if (a0 == c0) {
			return 0;
		}
		return a0 > c0 ? 1 : -1;
	};
	int b_side_x = side(A.x, B.x);
	int b_side_y = side(A.y, B.y);
	int c_side_x = side(A.x, C.x);
	int c_side_y = side(A.y, C.y);
	bool xopp = b_side_x * c_side_x == -1;
	bool yopp = b_side_y * c_side_y == -1;
	if (xopp && yopp) {
		cout << 1 << "\n";
	} else if (xopp) {
		cout << min(abs(A.y-B.y),abs(A.y-C.y)) + 1 << "\n";
	} else if (yopp) {
		cout << min(abs(A.x-B.x),abs(A.x-C.x)) + 1 << "\n";
	} else {
		cout << min(abs(A.x-B.x),abs(A.x-C.x)) + min(abs(A.y-B.y),abs(A.y-C.y)) + 1 << "\n";
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
