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

    // x = a/(b-a)
    // floor(a/x) = b-a
    // 
    // a > b-a
    // 2(2^n*a) > b
    // 2^n > 1/2*(b/a)
    // 2^n >  1/2*b
    // ceil(a/(b-a)) = x
    // b - a should be slightly up
    // 
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    vi dp2(3001);

    while(t--) {
        int n,k;
        cin >> n >> k;
        vi B(n);
        vi C(n);
        rep(i, 0, n) cin >> B[i];
        rep(i, 0, n) cin >> C[i];
        vi costs(n);
        rep(i, 0, n) {
            if (B[i] == 1) { 
                costs[i] = 0;
                continue;
            }
            dp2[1] = 0;
            rep(j, 2, B[i]+1) {
                dp2[j] = 1e9;
            }
            rep(j, 1, B[i]+1) {
                rep (x, 1, j+1) {
                    dp2[j+j/x] = min(dp2[j+j/x], dp2[j] + 1);
                }
            } 
            costs[i] = dp2[B[i]];
        }
        k = min(12*n, k);
        // trav(a, costs) cout << a << ' ';
        // cout << '\n';

        // dp[0][0] = 0
        // dp[0][x] = 0
        // dp[n][x] = max(C[n-1] + dp[n-1][x-costs[n-1]], dp[n-1][x]) if x >= costs[n-1] 
        // else dp[n+1][x]
        vector<vi> dp(2, vi(k + 1));
        rep(i, 0, k+1) {
            dp[0][i] = 0;
        }
        rep(i, 1, n+1) {
            rep(j, 0, k+1) {
                if (j >= costs[i-1]) {
                    dp[i%2][j] = max(C[i-1] + dp[(i-1)%2][j-costs[i-1]], dp[(i-1)%2][j]);
                } else {
                    dp[i%2][j] = dp[(i-1)%2][j];
                }
            }
        }
        // trav(a, dp) { 
        //     trav(b, a) cout << b << ' ';
        //     cout << '\n';
        // }
        // cout << '\n';


        cout << dp[n%2][k] << '\n';
    }

    return 0;
}