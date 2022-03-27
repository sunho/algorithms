#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <numeric>
using namespace std;

using ll = long long;
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set<pair<int, int>> soc; // soc, id
        int id = 1;
        for(int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            soc.insert(make_pair(k, id++));
        }
        int count = 0;
        vector<pair<int, int>> ans;
        while (soc.size() >= 2) {
            auto jt = --(--soc.end());
            if (jt->first == 0) { 
                soc.erase(jt);
                continue;
            }
            auto it = --soc.end();
            int a = it->second, b = jt->second;
            ans.push_back(make_pair(a,b));
            ++count;
            soc.insert(make_pair(it->first-1, it->second));
            soc.insert(make_pair(jt->first-1, jt->second));
            soc.erase(jt);
            soc.erase(it);
        }
        cout << count << endl;
        for (auto x : ans) cout << x.first << " " << x.second << endl;
    }
    return 0;
}