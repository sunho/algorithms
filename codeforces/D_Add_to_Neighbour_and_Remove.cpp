#include <iostream>
#include <algorithm>

using namespace std;

int INF = 9999999999999;


int solve(int a[200000], int i, int r, int n, int maxn, int minn) {
    if (maxn != INF && maxn - minn > 2) return 0;
    if (r == 0) return 1;
    if (i == n) return 0;
    return solve(a, i + 1, r - 1, n, max(a[i], maxn), min(a[i], minn)) + solve(a, i + 1, r, n, maxn, minn);
}

int main() {
    int a[200000];
    int t;

    cin >> t;
    
    for (int l = 0; l < t; ++l) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << solve(a, 0, 3, n, INF, -INF) << endl;
    }
}