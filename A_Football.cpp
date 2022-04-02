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
    string s;
    cin >> s;
    bool ans = false;
    int cnt = 1;
    for(int i=0;i<s.size();i++) {
        if (i != 0) {
            if (s[i] == s[i-1]) cnt++;
            else cnt = 1;
        }
        if (cnt >= 7) ans = true;
    }
    if (ans)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
