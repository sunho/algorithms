#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand() uniform_int_distribution<int>(0, UINT_MAX)(rng)

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> nums(n);
        for(int i=0;i<n;i++) cin >> nums[i];
        sort(nums.begin(),nums.end());

        vector<ll> sums(n+1, 0);
        sums[0] = nums[0];
        for (int i = 0; i < n; i++)
            sums[i+1] = sums[i] + nums[i];
        bool okay = false;
        //1 2 | 10
        // 1 2 3 | 9 10

        for(int i=2;i<=n-1;i++) {
            int cnta = i;
            int cntb = i-1;
            ll suma = sums[i] - sums[0];
            ll sumb = sums[n] - sums[n-i+1];
            if (sumb > suma) {
                okay = true;
            }
        }
        if (okay) cout << "YES\n"; else cout << "NO\n";
    }

    return 0;
}