#include <iostream>
#include <algorithm>
using namespace std;

#define N 101
int dp[N];
// n*10 mod d
// (n mod d* 10 mod d) mod d
// n mod d - p mod d = (n-p) * 10 mod d
// n > p
// 91, 92, 93, 94, 95, 96, 97, 98, 99 these will cover all the modulars a - n*d will make all possible
// from 100 and on, everything possible

bool islucky(int n, int d) {
    while (n >= 1) {
        if (n % 10 == d) {
            return true;
        }
        n/=10;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int q,d;
        cin >> q >> d;
        for (int i=1; i<= 100; ++i) {
            dp[i] = 0;
        }
        for (int i=d; i <= 100; ++i) {
            if (islucky(i,d)) {
                dp[i] = 1;
            } else {
                dp[i] = dp[i - d];
            }
        }
        for (int i=0; i<q; ++i) {
            int a;
            cin >> a;
            if (a >= 100) {
                cout << "YES" << endl;
            } else {
                cout << (dp[a] ? "YES" : "NO") << endl;
            }
        }
    }
    return 0;
}