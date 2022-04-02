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
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    int m;
    cin >> m;
    vector<int> B(m);
    for(int i=0;i<m;i++){
        cin >> B[i];
    }
    sort(all(A));
    sort(all(B));
    auto calc = [&](int d) {
        ll a = upper_bound(all(A), d)-A.begin();
        ll b = upper_bound(all(B), d)-B.begin();
        return pair<ll,ll>((n-a)*3 + a*2, (m-b)*3 + b*2);
    };
    const ll inf = 1e9;
    pair<ll,ll> ans;
    pair<ll,ll> maxi = {-inf,-inf};
    for(int i=0;i<n;i++) {
        for (auto cand : {calc(A[i]-1),calc(A[i])}) {
            if (ckmax(maxi, {cand.x - cand.y, cand.x})) {
                ans = cand;
            }
        }
    }
    for(int i=0;i<m;i++) {
        for (auto cand : {calc(B[i]-1),calc(B[i])}) {
            if (ckmax(maxi, {cand.x - cand.y, cand.x})) {
                ans = cand;
            }
        }
    }
    cout << ans.x << ":" << ans.y << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
