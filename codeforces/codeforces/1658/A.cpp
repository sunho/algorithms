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
    while (t--) {
        int n;
        cin >> n;
        string s;
        rep(i,0,n) {
            char c;
            cin >> c;
            s.push_back(c);
        }
        int cnt = 0;
        rep(i, 0, n-1) {
            if (s[i] == '0' && s[i+1] == '0') {
                cnt += 2;
            }
        }
        rep(i, 0, n-2) {
            if (s[i] == '0' && s[i+1] == '1' && s[i+2] == '0') {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    
    return 0;
}
