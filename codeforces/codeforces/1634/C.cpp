#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
const int N = 500;
int lp[N+1];
vector<int> pr;
int main() { 
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << "YES" << endl;
            for (int i = 1; i <= n; ++i) {
                cout << i << endl;
            }
            continue;
        }
        if (n % 2 != 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i = 1; i <= k*n; i+=2*k ) {
            for (int j = i; j < i + 2*k; j+=2) {
                cout << j << " ";
            }
            cout << endl;
            for (int j = i + 1; j < i + 2*k; j+=2) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    return 0;
}