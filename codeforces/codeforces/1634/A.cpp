#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int d, k;
        cin >> d >> k;
        string str;
        cin >> str;
        string rstr = str;
        reverse(rstr.begin(), rstr.end());
        if (k == 0) {
            cout << 1 << endl;
        } else if (str == rstr) {
            cout << 1 << endl;
        } else { 
            cout << 2 << endl;
        }
    }
    return 0;
}