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
    vector<int> A(n);
    vector<int> B(n);
    for(int i=0;i<n;i++) cin >> A[i];
    for(int i=0;i<n;i++) cin >> B[i];
    map<int,int> cnt;
    for(int i=0;i<n;i++) {
        cnt[A[i]]++;
        cnt[B[i]]++;
    }
    pair<int,int> ans;
    for(int i=0;i<n;i++){
        if (A[i]==B[i]) ans.x++;
    }
    for (auto [x,c] : cnt) {
        if (c == 2) {
            ans.y++;
        }
    }
    ans.y -= ans.x;
    cout << ans.x << "\n" << ans.y << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
