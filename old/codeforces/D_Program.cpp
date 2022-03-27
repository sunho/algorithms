#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    // max[i] = assuming current = 0, max (current) value
    int maxDP[200001];
    // min[i] = vice versa
    int minDP[200001];
    // current value given execed till i (inclusive)
    int current[200001];
    int maxForward[200001];
    int minForward[200001];

    char program[200001];
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; ++i) {
            cin >> program[i];
        }
        
        if (program[n] == '+') {
            maxDP[n] = 1;
            minDP[n] = 0;
        } else {
            maxDP[n] = 0;
            minDP[n] = -1;
        }

        for (int i = n - 1; i >= 1; --i) {
            if (program[i] == '+') {
                maxDP[i] = maxDP[i+1] + 1;
                if (minDP[i+1] != 0) {
                    minDP[i] = minDP[i+1] + 1;
                } else {
                    minDP[i] = 0;
                }
            } else {
                if (maxDP[i+1] != 0) {
                    maxDP[i] = maxDP[i+1] - 1;
                } else {
                    maxDP[i] = 0;
                }
                minDP[i] = minDP[i+1] - 1;
            }
        }

        int c = 0;
        int minc = 0;
        int maxc = 0;
        for (int i = 1; i <= n; ++i) {
            if (program[i] == '+') {
                ++c;
            } else {
                --c;
            }
            current[i] = c;
            minc = min(minc, c);
            maxc = max(maxc, c);
            minForward[i] = minc;
            maxForward[i] = maxc;
        }

        while(m--) {
            int l, r;
            cin >> l >> r;
            int cc = 0;
            int minc = 0;
            int maxc = 0;
            if (l != 1) {
                cc = current[l-1];
                minc = minForward[l-1];
                maxc = maxForward[l-1];
            }
            if (r != n) {
                cout << max(maxc, cc + maxDP[r+1]) - min(minc, cc + minDP[r+1]) + 1 <<endl;
            } else {
                cout << maxc - minc + 1 << endl;
            }
        }
    }
    return 0;
}