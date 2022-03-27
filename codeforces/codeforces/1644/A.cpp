#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define ceildiv(a,b) (((a) + (b) - 1) / (b))
#define MOD 11092019
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        set<char> keys;
        rep(i, 0, sz(s)) {
            if ('a' <= s[i] && s[i] <= 'z') {
                keys.insert(s[i]);
            } else {
                char c = tolower(s[i]);
                if (keys.find(c) == keys.end()) {
                    cout << "NO" << '\n';
                    goto done;
                }
            }
        }
        cout << "YES" << '\n';
done:
;
    }

    return 0;
}