#include <iostream>
#include <array>
#include <vector>

using namespace std;

typedef struct {
	string name;
	int volume;
	int desire;
} item;

array< array<int, 1000>, 100> memory;
vector<item> items;

int pack(int n, int w) {
	auto& m = memory[n][w];
	if (n == items.size()) {
		return 0;
	}
	if (w == 0) {
		return 0;
	}
	if (m != -1) {
		return m;
	}

	auto i = items[n];
	auto cand = pack(n+1, w);
	if (w >= i.volume) {
		auto cand2 = pack(n+1, w - i.volume) + i.desire;
		if (cand2 > cand) {
			return m = cand2;
		}
	}
	return m = cand;
}

int main() {
	int s;
	cin >> s;

	for (int i = 0; i < s; i++) {
		for (auto& a : memory) {
			fill(a.begin(), a.end(), -1);
		}
		items.clear();

		int n, w;
		cin >> n >> w;
		for (int j = 0; j < n; j++) {
			item it;
			cin >> it.name >> it.volume >> it.desire;
			items.push_back(it);
		}

		cout << pack(0, w) << endl;
	}
	return 0;
}
