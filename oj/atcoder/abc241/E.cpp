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
    ll n,k;
    cin >> n >> k;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    set<int> visited;
    vector<int> cycle;
    int idx = 0;
    while(!visited.count(idx)){
        visited.insert(idx);
        cycle.push_back(idx);
        idx += A[idx];
        idx %= n;
    }
    int j=0;
    while(true) {
        if(cycle[j] == idx) {
            break;
        }
        j++;
    }
    vector<int> B;
    vector<int> C;
    for(int i=0;i<j;i++){
        B.push_back(cycle[i]);
    }  
    for(int i=j;i<cycle.size();i++){
        C.push_back(cycle[i]);
    }
    ll ans = 0;
    if (k <= B.size()) {
        for(int i=0;i<k;i++){
            ans += A[ans % n];
        }
    } else {
        for(int i=0;i<B.size();i++){
            ans += A[ans % n];
        }
        k-=B.size();
        ll sum = 0;
        for(int i=0;i<C.size();i++){
            sum += A[C[i]];
        }
        ans += sum * (k/C.size());
        k %= C.size();
        for(int i=0;i<k;i++){
            ans += A[ans % n];
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
