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
    pair<int,int> a,b,c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    set<pair<int,int>> S;
    S.insert(a);
    S.insert(b);
    S.insert(c);
    pair<int,int> mini = {min({a.x,b.x,c.x}),min({a.y,b.y,c.y})};
    pair<int,int> maxi = {max({a.x,b.x,c.x}),max({a.y,b.y,c.y})};
    int w = maxi.x - mini.x;
    int h = maxi.y - mini.y;
    vector<pair<int,int>> cands ={{mini.x,mini.y}, {mini.x + w, mini.y}, {mini.x, mini.y+h}, {maxi.x, maxi.y}};
    for (auto cand : cands) {
        if (!S.count(cand)) {
            cout << cand.x << " " << cand.y << "\n";
            break;
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
