#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(int T) {
    int r,c;
    cin >> r >> c;
    cout << "Case #" << T << ":\n";
    for (int i=0;i<r*2+1;i++) {
        for(int j=0;j<c*2+1;j++){
            if (i >= 2 || j >= 2) {
                if (i&1) {
                    if (!(j&1)) {
                        cout << "|";
                        continue;
                    }
                } else {
                    if (j&1) {
                        cout << "-";
                        continue;
                    } else {
                        cout << "+";
                        continue;
                    }
                }
            }
            cout << ".";
        }
        cout << "\n";
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);

    return 0;
}
