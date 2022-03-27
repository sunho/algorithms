#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    cin >> t;

    vector<int> dis_sets;

    while (t--) {
        int n;
        cin >> n;
        // 1 3
        dis_sets.resize(0);
        dis_sets.reserve(n);
        int i;
        for (int _ = 0; _ < n; _++) {
            cin >> i;
            int j = upper_bound(dis_sets.begin(), dis_sets.end(), i) - dis_sets.begin();
            if (j == dis_sets.size()) {
                dis_sets.push_back(i);
            } else {
                int maxi = dis_sets[dis_sets.size()-1];
                dis_sets.resize(j+1);
                dis_sets[j] = maxi;
            }
        }
        cout << dis_sets.size() << endl;
    }

    return 0;
}