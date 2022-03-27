    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    using pii = pair<int, int>;
    using vi = vector<int>;
    #define x first
    #define y second
    #define rep(i,a,b) for(int i = a; i < (b); ++i)
    #define all(x) begin(x), end(x)
    #define trav(x,a) for(auto& x : (a))
    #define endl '\n'
    template<class T> bool ckmin(T&a, const T&b) { bool B = a > b; a = min(a,b); return B; }
    template<class T> bool ckmax(T&a, const T&b) { bool B = a < b; a = max(a,b); return B; }
    template <typename T,typename U> pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) { return {l.first+r.first,l.second+r.second}; }
     
    int main() {
        cin.sync_with_stdio(0); cin.tie(0);
        cin.exceptions(cin.failbit);
        #ifdef _DEBUG
            freopen("input.txt", "r", stdin);
        	freopen("output.txt", "w", stdout);
        #endif
        int tt;
        cin >> tt;
        while (tt--) {
            int x, n;
            cin >> n;
            vi A(n);
            rep(i,0,n) {
                cin >> A[i];
            }
            cin >> x;
            rep(i,0,n) {
                A[i] -= x;
            }
            vector<ll> pf(n+1);
            rep(i,0,n) pf[i+1] = pf[i]+A[i];
            // 1 2 3 1 5
            // 1 2 3 
            // pf[i+1] >= pf[i]
            // 1 2 3        j = 0
            // 9 9 -3
            // 0 1 2
            // pf0, pf1, pf2, pf3, pf4, pf5
            // pf2 : pf0
            // pf3:  pf1, pf0
            // pf4:  pf2, pf1, pf0
            // pf5: pf3, pf2, pf1, pf0
            // dp[i][j] -> j - 1 == i - 1 -> dp[i+1][i+1] = dp[i][j] + 1
            // dp[i+1][j] + 1 if it's possible to include (pf[i+2] - pf[i] >= 0) and j - 1 != i - 1
            // default: dp[i+1][i+1]
            // a b 
            // a,b,c,d
     
            vector<vi> dp(n, vi(2,0));
            rep(j, 0, 2) {
                dp[0][j] = j;
            }
            rep(i, 1, n) {
                rep(j, 0, 2) {
                    if (j == 0) {
                        ckmax(dp[i][j], dp[i-1][j^1]);
                        ckmax(dp[i][j], dp[i-1][j]);
                    } else {
                        ckmax(dp[i][j], dp[i-1][0] + 1);
                        if (i >= 2) {
                            if (pf[i+1] >= pf[i-1] && pf[i+1] >= pf[i-2]) {
                                ckmax(dp[i][j], dp[i-1][1] + 1);
                            } else if (pf[i+1] >= pf[i-1]) {
                                ckmax(dp[i][j], dp[i-2][0] + 2);
                            }
                        } else if (pf[i+1] >= pf[i-1]) {
                            ckmax(dp[i][j], dp[i-1][1] + 1);
                        }
                    }
                    
                }
            }
            
            cout << max(dp[n-1][0], dp[n-1][1]) << '\n';
        }
     
     
        return 0;
    }