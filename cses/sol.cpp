#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct sik {
	long int a, b;
	sik(long int a, long int b) {
		this->a = a;
		this->b = b;
	}
};

int main() {
	int q;
	cin >> q;
	vector<sik> siks = vector<sik>();
	for (int i = 0; i < q; i++) {
		int query;
		cin >> query;
		if (query == 1) {
			long int a, b;
			cin >> a >> b;
			siks.push_back(sik(a, b));
		}
		else if (query == 2) {
			int x;
			cin >> x;
			int value = 1;
			for (int i = 0; i < siks.size(); i++) {
				value *= siks[i].a * x + siks[i].b;
			}
			if (value == 0) cout << 0 << endl;
			else if (value > 0) cout << "+" << endl;
			else if (value < 0) cout << "-" << endl;
		}
	}
}