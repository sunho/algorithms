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
    vector<vector<int>> A(n, vector<int>(n));
    for(int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> A[i][j];
        }
    }
    
    vector<ll> d1((n-1)*2+1), d2((n-1)*2+1);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            d1[i+j]+=A[i][j];
            d2[i-j+n-1]+=A[i][j];
        }
    }

    array<pair<ll, pair<int, int>>, 2> ans;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ckmax(ans[(i+j)%2], {d1[i+j] + d2[i-j+n-1] - A[i][j], {i,j}});
        }
    }
    
    cout << ans[0].first + ans[1].first << '\n';
    for (auto a : ans) {
        cout << a.second.x + 1 << " " << a.second.y + 1 << " ";
    }
    cout << '\n';
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
