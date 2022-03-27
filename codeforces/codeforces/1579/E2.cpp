#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <sstream>
#include <numeric>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

using ll = long long;
#define endl '\n'


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    ordered_set last;
    while(t--) {
        last.clear();
        int id = 0;
        int n;
        cin >> n;
        ll inv = 0;
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            int more = last.size() - last.order_of_key({k, n+1});
            int less = last.order_of_key({k, 0});
            inv += min(more,less);
            last.insert({k, id++});
        }
        cout << inv << endl;
    }
    return 0;
}