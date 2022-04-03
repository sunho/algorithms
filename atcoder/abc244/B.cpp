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
    string s;
    cin >> n >> s;
    pair<int,int> X = {0,0};
    vector<pair<int,int>> dirs = {{1,0},{0,-1}, {-1,0}, {0,1}};
    int idx = 0;
    for(int i=0;i<n;i++) {
        if (s[i] == 'R') {
            idx ++;
            idx %= 4;
        } else {
            auto dir = dirs[idx];
            X.x += dir.x, X.y += dir.y;
        }
    }
    cout << X.x << " " << X.y << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
