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
    vector<pair<int,int>> A(n);
    for(int i=0;i<n;i++) {
        cin >> A[i].y >> A[i].x;
    }
    string S;
    cin >> S;
    vector<tuple<int,int,char>> B;
    for(int i=0;i<n;i++) B.push_back({A[i].x,A[i].y,S[i]});
    sort(all(B));
    bool ans = false;
    int idx = 0;
    while (idx < n) {
        int cury = get<0>(B[idx]);
        while (idx < n && get<0>(B[idx]) == cury && get<2>(B[idx]) == 'L') {
            idx++;
        }
        if (idx == n) break;
        if (get<0>(B[idx]) != cury) continue;
        while (idx < n && get<0>(B[idx]) == cury) {
            auto [y,x,dir] = B[idx];
            if (dir == 'L') {
                ans = true;
                break;
            }
            idx++;
        }
    }
    if (ans) cout << "Yes" << '\n';
    else cout << "No" << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
