#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll b = 0;
        for (int i = 0; i < n; i++) {
            ll k;
            cin >> k;
            b |= k;
        }
        cout << b << '\n';
    }

    return 0;
}
