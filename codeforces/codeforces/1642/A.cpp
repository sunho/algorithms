#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    
    while (t--) {
        vector<pii> verts;
        rep(i, 0, 3) {
            int a,b;
            cin >> a >> b;
            verts.push_back({a,b});
        }
        rep(i,0,3) {
            rep(j,0,3) {
                if (i == j) continue;
                if (verts[i].second == verts[j].second) {
                    if (verts[3 - i - j].second < verts[i].second) {
                        cout << abs(verts[j].first - verts[i].first) << '\n';
                        goto done;
                    }
                }
            }
        }
        cout << '0' << '\n';
done:
;
    }

    return 0;
}