#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand() uniform_int_distribution<int>(0, UINT_MAX)(rng)

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        map<int, int> X;
        map<int, int> Wm;
        vector<pii> W;
        for(int i=0;i<m;i++) {
            int x, w;
            cin >> x >> w;
            X[i] = x;
            Wm[i] = w;
            W.push_back({w,i});
        }
        sort(W.begin(),W.end());
        vector<pii> ans;
        for(int i=0;i<2*n;i++) {
            int id = W[i].second;
            ans.push_back({X[id], id});
        }
        sort(ans.begin(), ans.end());  
        int sum = 0;
        for(int i=0;i<2*n;i++) {
            sum += Wm[ans[i].second];
        }
        cout << sum << '\n';
        for(int i=0;i<n;i++) {
            cout << (ans[i].second + 1) << " " << (ans[2*n - i -1].second + 1) << '\n';
        }
    }

    return 0;
}