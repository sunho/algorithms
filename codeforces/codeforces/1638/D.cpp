#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int A[1001][1001];
bool visited[1001][1001];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    const auto is_square = [&](int i, int j) {
        return A[i][j] == A[i][j+1] && A[i][j] == A[i+1][j] && A[i+1][j+1] == A[i][j];
    };

    vector<tuple<int, int, int>> ans;
    queue<pair<int, int>> qu; 
    int n,m;
    int c;
    const auto count_c = [&](int i, int j) {
        if (i < 0 || i + 1 >= n || j < 0 || j + 1 >= m) return -1;
        int cnt = 0;
        int mi = 0;
        int dd[] = {A[i][j], A[i+1][j], A[i][j+1], A[i+1][j+1]};
        auto it = find_if(begin(dd), end(dd), [](int cc) { return cc != -1; });
        if (it == end(dd)) return -1;
        int c = *it;
        pair<int, int> locs[] = {
            {i, j},
            {i+1, j},
            {i, j+1},
            {i+1, j+1}
        };
        for (auto loc : locs) {
            int x,y;
            tie(x,y) = loc;
            if (A[x][y] == c) cnt++;
            if (A[x][y] == -1) mi++;
        }
        if (cnt + mi != 4) return -1;
        if (mi == 4) return -1;
        return cnt;
    };

    const auto fill_ij = [&](int i, int j) {
        A[i][j] = -1;
        A[i][j+1] = -1;
        A[i+1][j] = -1;
        A[i+1][j+1] = -1;
        pair<int, int> locs[] = {
            {i-1, j-1},
            {i-1, j},
            {i-1, j+1},
            {i, j-1},
            {i, j+1},
            {i+1, j-1},
            {i+1, j},
            {i+1, j+1},
        };

        for (auto loc : locs) {
            if (!visited[loc.first][loc.second] && count_c(loc.first, loc.second) != -1) {
                qu.push({loc.first, loc.second});
            }
        }
    };

    cin >> n >> m;
    ans.reserve(n*m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            if (is_square(i,j)) {
                ans.push_back({i,j, A[i][j]});
                fill_ij(i,j);
            }
        }
    }
    while (!qu.empty()) {
        int x,y;
        tie(x,y) = qu.front();
        qu.pop();
        if (visited[x][y]) continue;
        visited[x][y] = 1;
        int dd[] = {A[x][y], A[x+1][y], A[x][y+1], A[x+1][y+1]};
        auto it = find_if(begin(dd), end(dd), [](int cc) { return cc != -1; });
        if (it == end(dd)) continue;
        int c = *it;
        ans.push_back({x,y,c});
        fill_ij(x,y);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != -1) {
                cout << -1 << '\n';
                goto done;
            } 
        }
    }
    cout << ans.size() << '\n';
    for (int i = ans.size()-1; i >= 0; i --) {
        int x,y,c;
        tie(x,y,c) = ans[i];
        cout << x+1 << ' ' << y + 1 << ' ' << c << '\n';
    }
done:
    ;

    return 0;
}