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

template<typename T>
inline bool extbit(size_t bit_position, const T value) {
    return ((value >> bit_position) & 1) != 0;
}

int main() {
     #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int T;
    cin >> T;
    rep(t, 1, T+1) {
        int n;
        cin >> n;
        string S;
        cin >> S;
        auto match = [&](int mask, string s) {
            rep(i, 0, s.size()) {
                int c = extbit(s.size()-i-1, mask) + '0';
                if (s[i] != '?' && s[i] != c) {
                    return false;
                }
            }
            return true;
        };
        auto check5 = [&](int i) {
            return !(extbit(0, i) == extbit(4, i) && extbit(1, i) == extbit(3, i));
        };
        auto check6 = [&](int i) {
            bool f6 = !(extbit(0, i) == extbit(5, i) && extbit(1, i) == extbit(4, i) && extbit(2, i) == extbit(3, i));
            bool f50 = !(extbit(0, i) == extbit(4, i) && extbit(1, i) == extbit(3, i));
            bool f51 = !(extbit(1, i) == extbit(5, i) && extbit(2, i) == extbit(4, i));
            return f6 && f50 && f51;
        };
        auto solve = [&](int s, auto&& check) {
            bool ans = false;
            vector<vi> dp(n-s+2, vi(1<<s));
            int MSK = (1<<s) - 1;
            rep(i, 0, 1<<s) {
                dp[0][i] = 1;
            }
            rep(i, 0, n-s+1) {
                rep(mask, 0, 1<<s) {
                    int newmask = (mask << 1) & MSK;
                    if (dp[i][mask] && check(newmask) && match(newmask, S.substr(i, s))) {
                        dp[i+1][newmask] = 1;
                    }
                    if (dp[i][mask] && check(newmask|1) && match(newmask | 1, S.substr(i, s))) {
                        dp[i+1][newmask | 1] = 1;
                    }
                }
            }
            rep(mask, 0, 1<<s) {
                if (dp[n-s+1][mask]) {
                    ans = true;
                    break;
                }
            }
            return ans;
        };
        bool ans = true;
        if (S.size() == 5) {
            ans = solve(5, check5);
        } else if (S.size() >= 6) {
            ans = solve(6, check6);
        }

        if (ans) {
            cout << "Case #" << t << ": " << "POSSIBLE" << endl;
        } else {
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
