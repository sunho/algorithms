#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

// we can swap any time => we can build string b by using chars of a
// as long as we have the same set of chars, b can be constructed
// group consecutives: (b_1, i_1), (b_2, i_2), ...
// (a_1, j_1), ...
// sum i_1 = sum j_1
// since we can swap freely, we can swap temporarily increase, and undo
// a_1 > b_1 => cannot be constructed
// if a_1 <= b_1, j_1 -= i_1 ...
// we want to first eliminate least b_i's, since b_i cannot be built if a_i's big
// we can use least a_i for builiding b_i's (least a_i > lesast b_i means dead end )
// we want to use as many a_i as possible at each step
// least a_i <= least b_i < next b_i < ...
// least a_i can be used to any b_i if it's valid
// next a_i might not be used to any b_i
// next a_i might be not be able to used on least b_i
// need to eliminate b_i first

int main() {
    int t;
    cin >> t;
    while(t--) {
        map<char, int> a;
        map<char, int> b;
        int n, k;
        cin >> n >> k;
        for (int i =0; i <n; ++i) {
            char c;
            cin >> c;
            ++a[c];
        }
        for (int i =0; i <n; ++i) {
            char c;
            cin >> c;
            ++b[c];
        }
    
        bool able = true;
        for (auto [cb, n]: b) {
            auto ca = a.begin();
            while(n != 0 && ca != a.end()) {
                if (ca->first > cb) {
                    break;
                }
                int reqn = n;
                int maxn = ca->second;
                if (ca->first < cb) {
                    reqn = n - (n%k);
                    maxn = ca->second - (ca->second % k);
                }
                if (reqn >= maxn) {
                    ca->second -= maxn;
                    n -= maxn;
                } else {
                    ca->second -= reqn;
                    n -= reqn;
                }
                if (ca->second == 0) {
                    ca = a.erase(ca);
                } else {
                    ++ca;
                }
            }
            if (n != 0) {
                able = false;
                break;
            }
        }
        if (able) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}