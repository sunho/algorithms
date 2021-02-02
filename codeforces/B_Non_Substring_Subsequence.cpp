#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        while (q--) {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            bool found = false;
            for(int i = l-1; i >= 0; --i) {
                if (s[i] == s[l]) {
                    found = true;
                    break;
                }
            }
            for (int i = r+1; i <s.size(); ++i) {
                if(s[i] == s[r]) {
                    found = true;
                    break;
                }
            }
            if (found) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}