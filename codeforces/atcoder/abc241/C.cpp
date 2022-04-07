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
    vector<vector<char>> M(n, vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> M[i][j];
        }
    }
    auto is_valid = [&](pair<int,int> v){
        return v.x >= 0 && v.x < n && v.y >= 0 && v.y < n;
    };
    bool ans = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pair<int,int> v = {i,j};
            vector<pair<int,int>> dirs = {{0,1},{1,0},{1,1},{1,-1}};
            for(auto dir : dirs){
                pair<int,int> u = v;
                int z=0;
                int rem=2;
                while(z < 6 && is_valid(u)) {
                    if (M[u.x][u.y] == '.') {
                        if (rem > 0) {
                            rem--;
                        } else {
                            break;
                        }
                    }
                    u.x += dir.x;
                    u.y += dir.y;
                    z++;
                }
                if (z == 6) {
                    ans = true;
                }
            }
        }
    }
    if(ans) {
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
