#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand() uniform_int_distribution<int>(0, UINT_MAX)(rng)

#define MOD 998244353

const int maxn = 5000;
int C[maxn + 1][maxn + 1];
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    C[0][0] = 1;
    for (int n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % MOD;
    }
    
    int n, k;
    cin >> n >> k;

    vi B(n); // B[0] = a0 B[1] = a1 + a0
    vi p(n+1);

    int cnt = 1;

    for(int i=0;i<n;i++) {
        char c;
        cin >> c;
        int a = c-'0';
        B[i] = a;
    }

    for(int i=0;i<n;i++) p[i+1] = p[i] + B[i];

    for(int l=0;l<n;l++) {
        for(int r=l+1;r<n;r++) {
            if (p[r+1] - p[l] > k || p[n] < k) continue;
            int len = r-l + 1;
            int ones = p[r+1] - p[l];
            len-=2;
            if (B[l] == 0) ones--;
            if (B[r] == 0) ones--;
            if (ones < 0 || len < 0) continue;
            (cnt += C[len][ones])%=MOD;
        }
    }

    cout << cnt << '\n';

    return 0;
}