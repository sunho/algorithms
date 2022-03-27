#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    cin >> t;

    vector<int> arr;
    while (t--) {
        int n, t;
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> t;
            arr[i] = t;
        }

        bool okay = true;
        int lo = 0, le = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                if (arr[i] < le) {
                    okay = false;
                    break;
                }
                le = arr[i];
            } else {
                if (arr[i] < lo) {
                    okay = false;
                    break;
                }
                lo = arr[i];
            }
        }
        if (okay) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}