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
    
    ll x,y;
    cin >> x >> y;
    string xx,yy;
    while(x) { 
        char c = (x%2) + '0';
        xx.push_back(c);
        x/=2;
    }
    while(y) { 
        char c = y%2 + '0';
        yy.push_back(c);
        y/=2;
    }

    reverse(all(xx));
    reverse(all(yy));
    bool okay = false;
    auto check = [&](string xx, string yy) {
        okay |= xx == yy;
        if (yy.size() > xx.size()) {
            int sn = yy.size();
            int n = yy.size() - xx.size();
            rep(i,0,n + 1) {
                int j = n-i;
                if (yy.substr(0, i).rfind("0") != string::npos) {
                    continue;
                }
                if (yy.substr(sn-j, j).rfind("0") != string::npos) {
                    continue;
                }
                if (xx[xx.size()-1] == '0' && i != 0) {
                    continue;
                }
                okay |= yy.substr(i,sn-n) == xx;
            }
        }
    };
    auto trim = [&](string xx) {
        int c = 0;
        reverse(all(xx));
        rep(i,0,xx.size()) {
            if (xx[i] == '1') break;
            c++;
        }
        return xx.substr(c);
    };
    check(xx,yy);
    check(trim(xx),yy);
    check(trim(trim(xx)),yy);
    check(trim(xx+'1'),yy);
    check(trim(trim(xx+'1')),yy);
    if (okay) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}
