#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand() uniform_int_distribution<int>(0, UINT_MAX)(rng)

int N = 1e9;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi ans;
        bool okay = true;
        ans.push_back(1);
        for(int i=1;i<n;i++) {
            ll prev = ans[i-1];
            if ( prev * 3 > N) {
                okay = false;
                break;
            }
            ans.push_back(prev*3);
        }
        if (!okay)  {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
            for (auto& x:ans) cout << x << " ";
            cout << '\n';
        }
    }
    return 0;
}