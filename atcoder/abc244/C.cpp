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
    int n;
    cin >> n;
    set<int> S;
    for(int i=1;i<=2*n+1;i++) S.insert(i);
    while(true) {
        cout << *S.begin() << "\n";
        S.erase(S.begin());
        cout << flush;
        int c;
        cin >> c;
        if (c == 0) {
            break;
        }
        S.erase(c);
    }
}

int main() {
    solve();

    return 0;
}
