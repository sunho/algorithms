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
        set<int> pws;
        int n;
        cin >> n;
        rep(i, 0, n) {
            int c;
            cin >> c;
            pws.insert(c);
        }

        rep(k, 1, n+1) {
            cout << max(k, (int)pws.size()) << ' ';
        }
        cout << '\n';
    }

    return 0;
}