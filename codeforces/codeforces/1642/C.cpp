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
        int n,x;
        cin >> n >> x;
        multiset<ll> nums;
        rep(i,0,n) {
            ll c;
            cin >> c;
            nums.insert(c);
        }
        int cnt = 0;
        for (auto it = nums.begin(); it != nums.end(); ) {
            ll dd = (*it) * x;
            auto jt = nums.find(dd);

            if (nums.end() == jt) {
                cnt++;
                ++it;
            } else {
                nums.erase(jt);
                it = nums.erase(it);
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}