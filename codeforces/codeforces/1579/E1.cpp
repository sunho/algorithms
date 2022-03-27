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
        list<int> li;
        while(n--) {
            int k;
            cin >> k;
            if (li.empty()) {
                li.push_back(k);
            } else if (k < li.front()) {
                li.push_front(k);
            } else {
                li.push_back(k);
            }
        }
        for (auto x : li) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}