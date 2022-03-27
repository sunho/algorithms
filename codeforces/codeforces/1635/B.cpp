#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    vector<int> A;
    while (t--) {
        int n;
        cin >> n;
        A.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int cnt = 0;
        for (int i = 1; i < n-1; i++) {
            if (A[i-1] < A[i] && A[i+1] < A[i]) {
                cnt++;
                if (i+2 >= n) {
                    A[i+1] = A[i];  
                } else {
                    A[i+1] = max(A[i], A[i+2]);
                }
            }
        }
        cout << cnt << '\n';
        for (auto x : A) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}