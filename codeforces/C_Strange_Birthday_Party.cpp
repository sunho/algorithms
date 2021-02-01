#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// c_K_i  vs c_j
// gain: c_K_i - c_j
// max gain: c_K_i - c_j is max
// assign of max_i c_K_i to min_j c_j 
// 
using ll = long long;
#define N 300000
int costs[N];
int main() {
    int t;
    cin >> t;
    priority_queue<pair<int, int>> q;
    while (t--) {
        int n,m;
        cin >> n >> m;

        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            --k;
            q.push({k, i});
        }

        for (int i = 0; i < m; ++i) {
            int c;
            cin >> c;
            costs[i] = c;
        }
        
        int lastpi = 0;
        ll sum = 0;
        while(!q.empty()) {
            auto [k, i] = q.top();
            q.pop();
            if (lastpi < m) {
                if (costs[lastpi] < costs[k]) {
                    sum += costs[lastpi++];
                } else {
                    sum += costs[k];
                }
            } else {
                sum += costs[k];
            }
        }
        cout << sum << endl;
    }
}