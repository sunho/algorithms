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
    int s,k;
    cin >> s >> k;
    vi fib;
    fib.push_back(1);
    while (fib.back() < s) {
        int n = min(fib.size(), (size_t)k);
        int sum = 0;
        rep(i,0,n) {
            sum += fib[fib.size()-i-1];
        }
        fib.push_back(sum);
    }
    vi ans;
    ans.push_back(0);
    while (s > 0) {
        int i = lower_bound(all(fib), s) - fib.begin();
        if (fib[i] == s) {
            ans.push_back(fib[i]);
            break;
        } else {
            --i;
            ans.push_back(fib[i]);
            s-=fib[i];
            fib.erase(fib.begin()+i);
        }
    }
    cout << ans.size() << "\n";
    trav(x, ans) cout << x << " ";


    return 0;
}