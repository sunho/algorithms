#include <iostream>
#include <string>
#include <algorithm>
#define For(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long

using namespace std;
class ABBA {
public:
    string canObtain(string initial, string target) {
            int n = target.length() - initial.length();
            For(i, 0, n) {
                    if (target.back() == 'A') {
                            target.pop_back();
                    } else {
                            target.pop_back();
                            reverse(target.begin(), target.end());
                    }
            }
            return (initial == target) ? "Possible" : "Impossible";
    }
};

int main() {
	ABBA abba;
	string str, str2;
	cin >> str >> str2;
	cout << abba.canObtain(str, str2);
}
