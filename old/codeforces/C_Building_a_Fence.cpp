#include <iostream>
#include <algorithm>

using namespace std;


int memo[200000][2] = { -1 };

bool solve(int i, int h, int *H, int K, int N) {
    if (i == N-1) {
        return h == H[i];
    }
    int bottom = h == H[i];
    if (h == H[i] || h == H[i] + K) {
        if (memo[i][bottom] != -1) return memo[i][bottom];
    }
    bool out = false;
    // Trying to get to the top of the available region
    if (h + K >= H[i+1] && h + K <= H[i+1] + K) {
        out |= solve(i+1, h + K, H, K, N);
    } else if (H[i+1] + K >= h - K && H[i+1] + K <= h + K) {
        out |= solve(i+1, H[i+1] + K, H, K, N);
    }
    // Trying to get to the bottom of the available region
    if (h - K >= H[i+1] && h - K <= H[i+1] + K) {
        out |= solve(i+1, h - K, H, K, N);
    } else if (H[i+1] >= h - K && H[i+1] <= h + K) {
        out |= solve(i+1, H[i+1], H, K, N);
    }
    if (h == H[i] || h == H[i] + K) {
        memo[i][bottom] = out;
    }
    return out;
}

int main() {
    int t;
    cin >> t;
    int h[200000];

    while (t--) {
        int n,k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }

        for (int i = 0; i <n; ++i) {
            memo[i][0] = -1;
            memo[i][1] = -1;
        }
        if (solve(0, h[0], h, k-1, n)) {
            cout << "YES" <<endl;
        } else {
            cout <<"NO" <<endl;
        }
    }
    return 0;
}