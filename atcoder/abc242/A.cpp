#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
    int a,b,c,x;
    cin >> a >> b >> c >> x;
    double p;
    if (x <= a) { 
        p = 1.0;
    } else if (x > b) {
        p = 0.0;
    } else {
        p = (double)c/(double)(b-a);
    }
    cout << setprecision(10) << p << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
