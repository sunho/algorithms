#include <iostream>

using namespace std;

void solve() {
	int n,a,b;
	cin >> n >> a >> b;
	int ans = 0;
	for (int i=0;i<=n/a;i++){
		if ((n-a*i) % b == 0) {
			ans = max(ans, i + (n-a*i)/b);
		}
	}
	cout << ans << "\n";
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
