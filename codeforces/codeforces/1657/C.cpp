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
        cin >> s;
        int i = 0;
        int len = 0;
        int ops = 0;
        while (i<n) {
            int j = i+1;
            char last = s[i];
            int stk = 0;
            while (j<n) {
                if (s[j] == ')' && last == '(' && stk == 0) {
                    break;
                }
                if (s[j] == last) {
                    break;
                }
                if (s[i] == '(') {
                    stk++;
                } else {
                    stk--;
                }
                j++;
            }
            if (j != n) {
                ops++;
                i = j+1;
            } else {
                len = n - i;
                break;
            }
        }
        cout << ops << " " << len << '\n';
    }

    return 0;
}
