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
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++) {
        cin >> A[i];
    }
    auto go = [&](int l, int r, int last, auto&& self) {
        if (l >= r) return 0;
        int ms = *min_element(A.begin() + l, A.begin() + r);
        int idx = l;
        int cost = ms-last;
        while (idx < r) {
            int i = idx;
            while (i < r) {
                if (A[i] == ms) {
                    break;
                }
                i++;
            }
            cost += self(idx, i, ms, self);
            idx = i+1;
        }
        return min(r-l, cost);
    };

    cout << go(0,n,0,go) << '\n';
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
