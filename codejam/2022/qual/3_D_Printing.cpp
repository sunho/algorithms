#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(int T) {
    array<array<int,4>,3> P;
    for(int i=0;i<3;i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        P[i] = {a,b,c,d};
    }
    array<int,4> mini = P[0];
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            mini[j] = min(mini[j], P[i][j]);
        }
    }
    int R = 1e6;
    for(int i=0;i<4;i++){
        if (mini[i] >= R) {
            mini[i] = R;
        }
        R-=mini[i];
    }
    cout << "Case #" << T << ": ";
    if (R > 0) 
        cout << "IMPOSSIBLE" << "\n";
    else {
        for (auto x : mini) {
            cout << x << " ";
        }
        cout << "\n";
    }

}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    for (int i=1;i<=t;i++)
        solve(i);

    return 0;
}
