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
    vector<char> S(3);
    vector<char> T(3);
    for(int i=0;i<3;i++) {
        cin >> S[i];
    }
    for(int i=0;i<3;i++) {
        cin >> T[i];
    }
    int cnt = 0;
    for(int i=0;i<3;i++){
        if (S[i] == T[i]) cnt++;
    }
    if (cnt == 3 || cnt == 0) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
