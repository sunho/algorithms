#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;

void solve(vector<bool>& used, int depth, vi& pos, int req) {
    if (req == depth) {
        n--;
        trav(i, pos) cout << i << ' ';
        cout << '\n';
        return;
    }
    if (depth < 2) {
        for (int i = sz(used)-1; i >= 1; i--) {
            if (!used[i]) {
                pos[depth] = i;
                used[i] = true;
                solve(used, depth+1, pos, req);
                used[i] = false;
                if (n == 0) {
                    return;
                }
            }
        }
    } else {
        int c = pos[depth-1] + pos[depth-2];  
        rep(i, 1, sz(used)) {
            if (!used[i] && i != c) {
                pos[depth] = i;
                used[i] = true;
                solve(used, depth+1, pos, req);
                used[i] = false;
                if (n == 0) {
                    return;
                }
            }
        }
    }   
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vi s;
        set<int> avail;
        rep(i, 1, n+1) {
            avail.insert(i);
        }
        auto pos = vi(n);
        auto used = vector<bool>(n+1);
        solve(used, 0, pos, n);
    }

}