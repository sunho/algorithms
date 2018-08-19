#include <iterator>
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main() {
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
    }

	vector<int> dp(n, 0);
	vector<int> choices(n, 0);
	dp[n - 1] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j < n; j++) {
			if (arr[i] < arr[j]) {
				auto cand = dp[j] + 1;
				if (cand > dp[i]) {
					choices[i] = j;
					dp[i] = cand;
				}
			}
		}
	}

	auto d = distance(dp.begin(), max_element(dp.begin(), dp.end()));
	vector<int> out;
	while(choices[d] != 0) {
		out.push_back(arr[d]);
		d = choices[d];
	}
	out.push_back(arr[d]);

	for (auto a : out) {
		cout << a << " ";
	}
	cout << endl;

    return 0;
}
