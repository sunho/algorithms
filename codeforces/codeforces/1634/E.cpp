#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand() uniform_int_distribution<int>(0, UINT_MAX)(rng)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int N = 4e5 + 100, H = 2e5 + 50;
multiset<pii> g[N];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    vector<vector<int>> ans(n);
    // starting from n, it's numbers
    vector<int> nums;
    map<int, int> cnt;
    map<int, int> conv;
    for(int i=0;i<n;i++) {
        int m;
        cin >> m;
        ans[i] = vi(m,-1);
        for(int j=0;j<m;j++) {
            int x;
            cin >> x;
            if (!cnt.count(x)) {
                conv[x] = cnt.size() + H;
            }
            cnt[x]++;
            g[i].insert({conv[x], j});
            g[conv[x]].insert({i, j});
        }
    }

    for (auto& x: cnt) {
        if (x.second % 2) {
            cout << "NO" << '\n';
            return 0;
        }
    }

    stack<int> st;
    for(int i=0;i<n;i++) {
        st.push(i);
    }
    while (!st.empty()) {
        int v = st.top();
        auto it = g[v].begin();
        if (it == g[v].end()) {
            st.pop();
        } else {
            int nv,nj;
            tie(nv,nj) = *it;
            if (v >= H) {
                ans[nv][nj] = 1;
            } else {
                ans[v][nj] = 0;
            }
            g[nv].erase(g[nv].lower_bound({v, nj}));
            g[v].erase(it);
            st.push(nv);
        }
    }


    cout << "YES" << '\n';
    for(int i=0;i<n;i++) {
        for (auto& x:ans[i]) {
            if (x == 1) cout << 'L'; else if (x == 0) cout << 'R'; else cout << "FUCk" << i << '\n';
        }
        cout << '\n';
    }

    return 0;
}