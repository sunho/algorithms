#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    vector<int> res;
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        res.resize(n);
        int c, cnt = 1;
        for (int i = 0; i < n; i++) {
            cin >> c;
            res[i] = c;
        }
        
        for (int i = 0; i < n; i++) {
            if (res[i] == cnt) {
                ++cnt;
            } else {
                break;
            }
        }

        if (cnt == n + 1) {
            for (auto x : res) {
                cout << x << " ";
            }
            cout << endl;
        } else {
            for (int i = cnt-1; i < n; i++) {
                if (res[i] == cnt) {
                    reverse(res.begin() + cnt - 1, res.begin() + i + 1); 
                    break;
                }
            }
            for (auto x : res) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}