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

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi A(n);
        rep(i, 0, n) cin >> A[i];
        sort(all(A));
        ll sum = 0;
        auto dec = [&](map<ll, int>& S, ll c) {
            if (S.count(c)) {
                S[c]--;
                if (S[c] == 0) {
                    S.erase(c);
                }
            }
        };
        map<ll, int> S;
        rep(i,0,n) {
            sum += A[i];
            S[A[i]]++;
        }
        bool okay = true;
        if (n==1) {
            okay = true;
        } else if (sum < n) {
            okay = false;
        } else {
            map<ll, int> cakes;
            cakes[sum]=1;
            rep(i,0,n-1) {  
                if (cakes.empty()) {
                    break;
                }
                auto it = cakes.end();
                --it;
                ll cake = it->first;
                ll cake1,cake2;
                if (cake % 2 == 0) {
                    cake1 = cake/2;
                    cake2 = cake/2;
                } else {
                    cake1 = cake/2 +1;
                    cake2 = cake/2;
                }
                if (S.count(cake1)) {
                    dec(S, cake1);
                } else {
                    cakes[cake1]++;
                }
                if (S.count(cake2)) {
                    dec(S, cake2);
                } else {
                    cakes[cake2]++;
                }
                dec(cakes, cake);
            }
            if (!S.empty()) {
                okay = false;
            }
        }
        if (okay) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
