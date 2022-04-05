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
    const ll inf = 1e18;
    ll n, x;
    cin >> n >> x;
    --x;
    string S;
    cin >> S;
    int outlevel = 0;
    for(int i=0;i<n;i++) {
        if (outlevel > 0) {
            if (S[i] == 'R' || S[i] == 'L') {
                outlevel++;
            } else {
                outlevel--;
            }
        } else {
            ll next;
            if(S[i] == 'R') {
                next = x*2 + 2;
            } else if (S[i] == 'L') {
                next = x*2 + 1;
            } else {
                next = (x-1)/2;
            }
            if (next >= inf) {
                outlevel = 1;
            } else {
                x = next;
            }
        }
    }
    cout << x + 1 << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
