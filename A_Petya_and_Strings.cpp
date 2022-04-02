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
    string s,t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (tolower(s[i]) < tolower(t[i])) {
            ans = -1;
            break;
        } else if (tolower(s[i]) > tolower(t[i])) {
            ans = 1;
            break;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
