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
    int n,k;
    cin >> n >> k;
    bool okay = true;
    int max_d = 0;
    vector<int> A(n);
    for (int i=0;i<n;i++) {
        cin >> A[i];
        ckmax(max_d, A[i]);
    }
    vector<vector<int>> D(max_d+1);
    for(int i=0;i<n;i++) {
        D[A[i]].push_back(i);
    }
    if (D[0].size() != 1) {
        okay = false;
    }

    vector<pair<int,int>> ans;
    for(int d=0;d<max_d;d++) {
        int c = D[d].size();
        int nc = D[d+1].size();
        if (c == 0) {
            okay = false;
            break;
        }
        int nn = (nc + c - 1) / c;
        if ((nn > k && d == 0) || (nn + 1 > k && d != 0)) okay = false;
        for(int i=0;i<c;i++) {
            for (int j=0;j<nn;j++) {
                if (i*nn+j < nc)
                    ans.push_back({D[d][i], D[d+1][i*nn+j]});
            }
        }
    }
    if (okay) {
        cout << ans.size() << "\n";
        for (auto x : ans) {
            cout << x.x + 1 << " " << x.y + 1 << "\n";
        }
    } else {
        cout << "-1" << '\n';
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
