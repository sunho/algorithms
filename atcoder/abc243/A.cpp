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
    int v;
    vector<int> A(3);
    cin >> v;
    for(int i=0;i<3;i++) cin >> A[i];
    int sum = 0;
    for(int i=0;i<3;i++) {sum += A[i];}
    v %= sum;
    vector<string> N = {"F","M","T"};
    for(int i=0;i<3;i++){
        if (v < A[i]) {
            cout << N[i];
            break;
        }
        v -= A[i];
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
