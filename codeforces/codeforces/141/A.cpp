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
    string s,t,k;
    cin >> s >> t >> k;
    map<char, int> cnt;
    for (char ch : s) {
        cnt[ch]++;
    }
    for (char ch : t) {
        cnt[ch]++;
    }
    bool ans = true;
    for (char ch : k) {
        if (cnt[ch] == 0) {
            ans = false;
        } else {
            cnt[ch]--;
        }
    }
    for (auto [ch, c] : cnt) {
        if (c != 0) ans = false;
    }
    if (ans) 
        cout << "YES" << '\n';
    else 
        cout << "NO" << '\n';
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
