#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

#define For(i,s,n) for(int i =(s); i < (n); ++i)
#define ll long long
#define N 1002

using namespace std;

void printCord(int i, int j, int p, int q) {
    For(z, i, p) cout << "D";
    For(z, j, q) cout << "R";
}

void printDP(int dp[N][N], int n) {
    cout << dp[n][n] << endl;
    int i = n, j = n;
    string str;
    while(i != 1 || j != 1) {
        if(dp[i-1][j] < dp[i][j-1]) {
            str += "D";
            --i;
        } else {
            str += "R";
            --j;
        }
    }
    reverse(str.begin(), str.end());
    cout << str << endl;
}

int main() {
    int zi, zj;
    int n, num[N][N], dp2[N][N], dp5[N][N];
    cin >> n;
    bool zero = false;
    memset(dp2, 60, sizeof dp2);
    memset(dp5, 60, sizeof dp5);
    For(i, 1, n + 1)
        For(j, 1, n + 1) {
            int t;
            scanf("%d", &t);
            if(t == 0) zero = true, zi = i, zj = j, num[i][j] = 1;
            else num[i][j] = t;
        }

    dp2[0][1] = dp5[0][1] = 0;
    For(i, 1, n + 1)
        For(j, 1, n + 1) {
            int u = 0, v = 0;
            int t = num[i][j];
            while(t % 2 == 0) t /= 2, u++;
            t = num[i][j];
            while(t % 5 == 0) t /= 5, v++;
            dp2[i][j] = min(dp2[i-1][j], dp2[i][j-1]) + u;
            dp5[i][j] = min(dp5[i-1][j], dp5[i][j-1]) + v;
        }

    if(zero && min(dp2[n][n], dp5[n][n]) >= 1) {
        cout << 1 << endl;
        printCord(1, 1, zi, zj);
        printCord(zi, zj, n, n);
    } else if(dp2[n][n] < dp5[n][n]) {
        printDP(dp2, n);
    } else {
        printDP(dp5, n);
    }

    return 0;
}