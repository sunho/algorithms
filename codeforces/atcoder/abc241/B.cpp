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
    int n,m;
    cin >> n >> m;
    multiset<int> A;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        A.insert(a);
    }
    bool ans = true;
    for(int i=0;i<m;i++){
        int b;
        cin >> b;
        auto it = A.find(b);
        if (it == A.end()) {
            ans = false;
        } else {
            A.erase(it);
        }
    }
    if (ans) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
