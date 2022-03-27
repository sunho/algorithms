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
        int n,d;
        cin >> n >> d;
        vi A(n);
        for(int i=0;i<n;i++) {
            cin >> A[i];
        }
        int mn = A[0] - 1;
        int minx = 0;
        for(int i=1;i<n;i++) {
            if (A[i] - A[i-1] - 1 < mn) {
                mn = A[i] - A[i-1] - 1;
                minx = i;
            }
        }
        vi B;
        for(int i=0;i<n;i++) {
            if (i != minx) {
                B.push_back(A[i]);
            }
        }
        auto calc = [&](const vi& B) {
            int maxi = B[0] - 1;
            int mini = B[0] - 1;
            for(int i=1;i<B.size();i++) {
                int del = B[i] - B[i-1] - 1;
                if (del > maxi) maxi = del;
                if (del < mini) mini = del; 
            }
            int ans = min(mini, max((maxi - 1)/2, d-B[B.size()-1]-1));
            return ans;
        };
        int ans = calc(B);
        if (minx != 0) {
            B.clear();
            minx--;
            for(int i=0;i<n;i++) {
                if (i != minx) {
                    B.push_back(A[i]);
                }
            }
            ans = max(ans, calc(B));
        }
       
        
        cout << ans << '\n';
    }

    return 0;
}