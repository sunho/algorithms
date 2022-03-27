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

    int T;
    cin >> T;
    rep(t, 1, T+1) {
        string N;
        cin >> N;
        ll sum = 0;
        rep(i, 0, N.size()) {
            sum += (N[i] - '0');
        }
        int ins = sum % 9 == 0 ? 0 : 9 - sum % 9;
        if (ins == 0 && N.size() == 1) {
            N = N+'0';
        } else {
            rep(i, 0, N.size()) {
                int c = N[i] - '0';
                if (i == 0 && ins == 0) {
                    continue;
                }
                if (c > ins) {
                    N.insert(N.begin() + i, ins + '0');
                    break;
                }
                if (i == N.size() - 1) {
                    N.insert(N.begin() + i+1, ins + '0');
                    break;
                }
            }
        }
        
        cout << "Case #" << t << ": ";
        cout << N << endl;
    }


    return 0;
}
