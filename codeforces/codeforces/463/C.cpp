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
    auto is_valid = [&](pair<int,int> cur) {
        return 0 <= cur.x && cur.x < n && 0 <= cur.y && cur.y < n;
    };
    vector<vector<ll>> dp(n, vector<ll>(n));
    auto add_diag = [&](pair<int, int> start, pair<int, int> offset) {
        ll sum = 0;
        pair<int,int> cur = start;
        while (is_valid(cur)) {
            sum += A[cur.x][cur.y];
            cur.x += offset.x, cur.y += offset.y;
        }
        cur = start;
        while (is_valid(cur)) {
            dp[cur.x][cur.y] += sum;
            cur.x += offset.x, cur.y += offset.y;
        }
    };
    auto set_diag = [&](auto& arr, pair<int, int> pos, ll val) {
        vector<pair<int, int>> dirs = {{-1,1}, {1,-1}, {1,1}, {-1,-1}};
        for (auto dir : dirs) {
            pair<int, int> cur = pos;
            while (is_valid(cur)) {
                arr[cur.x][cur.y] = val;
                cur.x += dir.x, cur.y += dir.y;
            }
        }
    };
    auto calc = [&]() {
        for (int i=0;i<n;i++) {
            add_diag({0,i}, {1, -1});
        }
        for (int i=1;i<n;i++) {
            add_diag({i,n-1}, {1, -1});
        }
        for (int i=0;i<n;i++) {
            add_diag({0,i}, {1, 1});
        }
        for (int i=1;i<n;i++) {
            add_diag({i,0}, {1, 1});
        }
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                dp[i][j] -= A[i][j];
            }
        }
    };
    calc();
    array<pair<ll, pair<int, int>>, 2> ans;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            ckmax(ans[(i+j)%2], {dp[i][j], {i,j}});
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
