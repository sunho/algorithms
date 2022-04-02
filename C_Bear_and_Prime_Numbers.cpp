#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
    const int N = 1e7;
    vector<int> lp(N+1);
    vector<int> pr;
    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }

    int n;
    cin >> n;
    int max_n = 0;
    vector<int> A(n);
    for(int i=0;i<n;i++) {
        cin >> A[i];
        ckmax(max_n,A[i]);
    }
    max_n+=2;
    vector<int> f(max_n+1);
    vector<int> pf(max_n+2);
    for(int i=0;i<n;i++) {
        int x = A[i];
        while(x > 1) {
            int l = lp[x];
            if (l == 0) {
                f[x]++;
                break;
            }
            f[l]++;
            while (x % l == 0) {
                x /= l;
            }
        }
    }
    for(int i=0;i<=max_n;i++) {
        pf[i+1]=pf[i]+f[i];
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++) {
        int l,r;
        cin >> l >> r;
        cout << pf[min(r,max_n)+1]-pf[min(l,max_n)] << '\n';
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    solve();
  

    return 0;
}
