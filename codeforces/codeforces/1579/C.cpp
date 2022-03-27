#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <sstream>
#include <numeric>
using namespace std;

using ll = long long;
#define endl '\n'

int n, m, k;
char D[10][19] = { 0 };
char B[10][19] = { 0 };

void dfs(int i, int j, int size = 0) {
    if (!D[i][j]) {
        return;
    }
    if (i >= n || j >= m) {
        return;
    }
    if (D[i+1][j+1]) {
        dfs(i +1, j + 1, size + 1);
    }
    if (size >= k) {
        for (int z = 1; z <= size; ++z) {
            if (!D[i-z][j+z]) {
                return;
            }
        }
        B[i][j] = 0;
        for (int z = 1; z <= size; ++z) {
            B[i-z][j+z] = 0;
        }
        for (int z = 1; z <= size; ++z) {
            B[i-z][j-z] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char c;
                cin >> c;
                if (c == '*') {
                    D[i][j] = 1;
                    B[i][j] = 1;
                } else {
                    D[i][j] = 0;
                    B[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dfs(i,j, 0);
            }
        }
        bool ans = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (B[i][j]) {
                    ans = false;
                }
            }
        }
        
        if (ans) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}